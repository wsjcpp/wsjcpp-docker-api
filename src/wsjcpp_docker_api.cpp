#include "wsjcpp_docker_api.h"
#include <wsjcpp_core.h>
#include <curl/curl.h>
#include <json.hpp>

// ---------------------------------------------------------------------
// WsjcppDockerImage

WsjcppDockerImage::WsjcppDockerImage() {
    TAG = "WsjcppDockerImage";
    m_sId = "";
    m_sParentId = "";
    m_nCreated = 0;
    m_nSharedSize = 0;
    m_nSize = 0;
    m_nVirtualSize = 0;
}

// ---------------------------------------------------------------------

bool WsjcppDockerImage::fillFromJson(const nlohmann::json &jsonResponse) {
    m_jsonOriginal = jsonResponse;
    auto it = jsonResponse.begin();
    for (; it != jsonResponse.end(); ++it) {
        std::string sKey = it.key();
        if (sKey == "ParentId") {
            m_sParentId = it.value();
        } else if (sKey == "Id") {
            m_sId = it.value();
        } else if (sKey == "Containers") {
            m_nContainers = it.value();
        } else if (sKey == "SharedSize") {
            m_nSharedSize = it.value();
        } else if (sKey == "VirtualSize") {
            m_nVirtualSize = it.value();
        } else if (sKey == "Size") {
            m_nSize = it.value();
        } else if (sKey == "Created") {
            m_nCreated = it.value();
        } else if (sKey == "RepoTags") {
            m_vRepoTags.clear();
            nlohmann::json arr = it.value();
            for (int i  = 0; i < arr.size(); i++) {
                std::string sTag = arr.at(i);
                m_vRepoTags.push_back(sTag);
            }
        } else if (sKey == "RepoDigests") {
            m_vRepoDigests.clear();
            nlohmann::json arr = it.value();
            for (int i  = 0; i < arr.size(); i++) {
                std::string sDigest = arr.at(i);
                m_vRepoDigests.push_back(sDigest);
            }
        } else if (sKey == "Labels") {
            nlohmann::json val = it.value();
            if (!val.is_null()) {
                auto it2 = val.begin();
                for (; it2 != val.end(); ++it2) {
                    std::string sKey2 = it2.key();
                    std::string sValue2 = it2.value();
                    m_mapLabels[sKey2] = sValue2;
                }
            }
        } else {
            WsjcppLog::warn(TAG, "Ignored key images: " + sKey);
            std::cout << it.key() << " | " << it.value() << "\n";
        }
        
    }
    return true;
}

// ---------------------------------------------------------------------

nlohmann::json WsjcppDockerImage::getJsonOriginal() {
    return m_jsonOriginal;
}

// ---------------------------------------------------------------------

std::string WsjcppDockerImage::getId() {
    return m_sId;
}

// ---------------------------------------------------------------------

std::string WsjcppDockerImage::getParentId() {
    return m_sParentId;
}

// ---------------------------------------------------------------------

long WsjcppDockerImage::getCreated() {
    return m_nCreated;
}

// ---------------------------------------------------------------------

std::map<std::string, std::string> WsjcppDockerImage::getLabels() {
    return m_mapLabels;
}

// ---------------------------------------------------------------------

std::vector<std::string> WsjcppDockerImage::getRepoDigests() {
    return m_vRepoDigests;
}

// ---------------------------------------------------------------------

std::vector<std::string> WsjcppDockerImage::getRepoTags() {
    return m_vRepoTags;
}

// ---------------------------------------------------------------------

long WsjcppDockerImage::getSharedSize() {
    return m_nSharedSize;
}

// ---------------------------------------------------------------------

long WsjcppDockerImage::getSize() {
    return m_nSize;
}

// ---------------------------------------------------------------------

long WsjcppDockerImage::getVirtualSize() {
    return m_nVirtualSize;
}

// ---------------------------------------------------------------------

long WsjcppDockerImage::getContainers() {
    return m_nContainers;
}

// ---------------------------------------------------------------------
// WsjcppDockerApi

WsjcppDockerApi::WsjcppDockerApi() {
    m_sApiVersionPrefix = "/v1.40/";
    m_bConneted = false;
    TAG = "WsjcppDockerApi(" + m_sApiVersionPrefix + ")";
}

// ---------------------------------------------------------------------

std::string WsjcppDockerApi::getDefaultUnixSocketPath() {
    return "/var/run/docker.sock";
}

// ---------------------------------------------------------------------

bool WsjcppDockerApi::isConnected() {
    return m_bConneted;
}

// ---------------------------------------------------------------------

bool WsjcppDockerApi::doConnectUnixSocketPath(const std::string &sDockerUnixSocketPath) {
    m_sDockerUnixSocketPath = sDockerUnixSocketPath;
    std::string sResponse;
    if (!requestGet(makeUrl("/containers/json?all=0"), sResponse)) {
        m_bConneted = false;
    } else {
        m_bConneted = true;
    }
    return m_bConneted;
}

// ---------------------------------------------------------------------
/*
 bool WsjcppDockerApi::getContainers(std::vector<WsjcppDockerContainer> &vContainers, std::string &sError) {
    if (!m_bConneted) {
        sError = "Not connected";
        return false;
    }

    // TODO curl with request get
    // GET /containers/json

    return true;
}
*/
// ---------------------------------------------------------------------

bool WsjcppDockerApi::getImages(std::vector<WsjcppDockerImage> &vImages, std::string &sError) {
    if (!m_bConneted) {
        sError = "Not connected";
        return false;
    }
    std::string sResponse = "";
    if (!requestGet(makeUrl("/images/json?all=0"), sResponse)) {
        sError = "Something wrong";
        return false;
    }
    // WsjcppLog::info(TAG, "sResponse = " + sResponse);
    nlohmann::json jsonResponse = nlohmann::json::parse(sResponse);
    int nSize = jsonResponse.size();
    for (int i = 0; i < nSize; i++) {
        nlohmann::json jsonImage = jsonResponse.at(i);
        // WsjcppLog::info(TAG, "image = " + jsonImage.dump(4));
        WsjcppDockerImage image; 
        image.fillFromJson(jsonImage);
        vImages.push_back(image);
    }
    return true;
}

// ---------------------------------------------------------------------

static size_t WsjcppDockerApi_CurlWrite_CallbackFunc_DataToStr(void *contents, size_t size, size_t nmemb, void *userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

// ---------------------------------------------------------------------

std::string WsjcppDockerApi::makeUrl(const std::string & sPath) {
    return "http://localhost/" + m_sApiVersionPrefix + sPath;
}

// ---------------------------------------------------------------------

bool WsjcppDockerApi::requestGet(const std::string &sURL, std::string &sResponse) {
    WsjcppLog::info(TAG, "sURL: '" + sURL + "'");
    std::string sUserAgent = "wsjcpp-docker-api/?";
    std::string readBuffer;
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init(); 
    if (curl) { 
        // curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L); //only for https
        // curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L); //only for https
        curl_easy_setopt(curl, CURLOPT_URL, sURL.c_str()); 
        curl_easy_setopt(curl, CURLOPT_UNIX_SOCKET_PATH, m_sDockerUnixSocketPath.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WsjcppDockerApi_CurlWrite_CallbackFunc_DataToStr); 
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        
        curl_easy_setopt(curl, CURLOPT_USERAGENT, sUserAgent.c_str());
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 50L);
        // curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
        res = curl_easy_perform(curl); 
        if (res != CURLE_OK) {
            WsjcppLog::err(TAG, "Curl failed, reason  " + std::string(curl_easy_strerror(res))); 
            curl_easy_cleanup(curl);
            return false;
        } else {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            if (response_code != 200) {
                WsjcppLog::info(TAG, "end " + std::to_string(response_code));
                // TODO remove file
                curl_easy_cleanup(curl);
                return false;
            }
        }

        // always cleanup
        curl_easy_cleanup(curl); 
    }
    sResponse = readBuffer;
    // WsjcppLog::info(TAG, "Response: " + readBuffer);
    return true;
}

// ---------------------------------------------------------------------
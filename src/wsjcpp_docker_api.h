#ifndef WSJCPP_DOCKER_API_H
#define WSJCPP_DOCKER_API_H

#include <string>
#include <vector>
#include <json.hpp>

// ---------------------------------------------------------------------

class WsjcppDockerContainer {

};

// ---------------------------------------------------------------------

class WsjcppDockerImage {
    
    public:
        WsjcppDockerImage();
        bool fillFromJson(const nlohmann::json &);
        nlohmann::json getJsonOriginal();
        std::string getId();
        std::string getParentId();
        long getCreated();
        std::map<std::string, std::string> getLabels();
        std::vector<std::string> getRepoDigests();
        std::vector<std::string> getRepoTags();
        long getSharedSize();
        long getSize();
        long getVirtualSize();
        long getContainers();

    private:
        std::string TAG;
        nlohmann::json m_jsonOriginal;
        std::string m_sId;
        std::string m_sParentId;
        long m_nCreated;
        std::map<std::string, std::string> m_mapLabels;
        std::vector<std::string> m_vRepoDigests;
        std::vector<std::string> m_vRepoTags;
        long m_nSharedSize;
        long m_nSize;
        long m_nVirtualSize;
        long m_nContainers;

};

// ---------------------------------------------------------------------

class WsjcppDockerApi {
    public:
        WsjcppDockerApi();
        std::string getDefaultUnixSocketPath();
        bool isConnected();
        bool doConnectUnixSocketPath(const std::string &sDockerUnixSocketPath);
        // bool getContainers(std::vector<WsjcppDockerContainer> &vContainers, std::string &sError);
        bool getImages(std::vector<WsjcppDockerImage> &vImages, std::string &sError);

    protected:
        std::string TAG;
        std::string makeUrl(const std::string &sPath);
        bool requestGet(const std::string &sPath, std::string &sResponse);

    private:
        std::string m_sApiVersionPrefix;
        std::string m_sDockerUnixSocketPath;
        bool m_bConneted;
};

#endif // WSJCPP_DOCKER_API_H
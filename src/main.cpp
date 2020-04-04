#include <string.h>
#include <iostream>
#include <algorithm>
#include <wsjcpp_core.h>
#include <wsjcpp_docker_api.h>

int main(int argc, const char* argv[]) {
    std::string TAG = "MAIN";
    std::string appName = std::string(WSJCPP_NAME);
    std::string appVersion = std::string(WSJCPP_VERSION);
    if (!WsjcppCore::dirExists(".logs")) {
        WsjcppCore::makeDir(".logs");
    }
    WsjcppLog::setPrefixLogFile("wsjcpp");
    WsjcppLog::setLogDirectory(".logs");
    WsjcppDockerApi dockerApi;

    std::string sUnixSocketPath = dockerApi.getDefaultUnixSocketPath();
    if (!dockerApi.doConnectUnixSocketPath(sUnixSocketPath) ) {
        WsjcppLog::err(TAG, "Could not connect to '" + sUnixSocketPath + "'");
        return -1;
    }
    // std::string sResponse;
    std::vector<WsjcppDockerImage> vImages;
    std::string sError;
    if (!dockerApi.getImages(vImages, sError)) {
        WsjcppLog::err(TAG, "Could not get list of images '" + sError + "'");
        return -1;
    }

    std::string sOutput = "\nImages: \n";
    for (int i = 0; i < vImages.size(); i++) {
        WsjcppDockerImage img = vImages[i];
        sOutput +=
            "\n"
            "  ID: " + img.getId() + "\n"
            "  SIZE: " + std::to_string(img.getSize()) + "\n";
        if (img.getParentId().length() > 0) {
            sOutput += "  PARENT-ID: " + img.getParentId() + "\n";
        }
        std::vector<std::string> vRepoTags = img.getRepoTags();
        std::string sTags = "";
        for (int n = 0; n < vRepoTags.size(); n++) {
            std::string sRepoTag = vRepoTags[n];
            std::vector<std::string> vRepoTag = WsjcppCore::split(sRepoTag, ":");
            sOutput += "  REPOSITORY: " + vRepoTag[0] + "\n";
            sOutput += "  TAG: " + vRepoTag[1] + "\n";
        }
        sOutput +=
            "  CREATED: " + std::to_string(img.getCreated()) + ", " + WsjcppCore::formatTimeForWeb(img.getCreated()) + "\n"
        ;

    }

    WsjcppLog::info(TAG, sOutput);
    return 0;
}


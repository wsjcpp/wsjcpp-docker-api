# wsjcpp-docker-api-wrapper

C++ implementation for docker-api (used curl)

Main documentation for docker here:

https://docs.docker.com/engine/api/v1.40/

## Integrate to your project

```
$ wsjcpp install "https://github.com/wsjcpp/wsjcpp-docker-api:master"
```

or include files:

* `src.wsjcpp/nlohmann_json/json.hpp`
* `src.wsjcpp/wsjcpp_core/wsjcpp_core.h`
* `src.wsjcpp/wsjcpp_core/wsjcpp_core.cpp`
* `src/wsjcpp_docker_api.h`
* `src/wsjcpp_docker_api.cpp`

## How to use

```
#include <wsjcpp_core.h>
#include <wsjcpp_docker_api.h>

... 

// get default unix socket path (for linux and for mac)
std::string sUnixSocketPath = dockerApi.getDefaultUnixSocketPath();
if (!dockerApi.doConnectUnixSocketPath(sUnixSocketPath) ) {
    WSJCppLog::err(TAG, "Could not connect to '" + sUnixSocketPath + "'");
    return -1;
}

// get list of images like a 'docker images'
std::vector<WsjcppDockerImage> vImages;
std::string sError;
if (!dockerApi.getImages(vImages, sError)) {
    WSJCppLog::err(TAG, "Could not get list of images '" + sError + "'");
    return -1;
}

```


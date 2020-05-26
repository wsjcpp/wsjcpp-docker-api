#include "unit_test_parse_wsjcpp_docker_image.h"
#include <vector>
#include <wsjcpp_core.h>
#include <wsjcpp_docker_api.h>
#include <json.hpp>

REGISTRY_WSJCPP_UNIT_TEST(UnitTestParseWsjcppDockerImage)

UnitTestParseWsjcppDockerImage::UnitTestParseWsjcppDockerImage()
    : WsjcppUnitTestBase("UnitTestParseWsjcppDockerImage") {
}

// ---------------------------------------------------------------------

void UnitTestParseWsjcppDockerImage::init() {
    // nothing
}

// ---------------------------------------------------------------------

bool UnitTestParseWsjcppDockerImage::run() {
    bool bTestSuccess = true;

    struct LTest {
        LTest(
            int nI,
            const std::string &sId,
            const std::string &sParentId,
            long nExpectedCreated,
            long nExpectedSharedSize,
            long nExpectedSize,
            long nExpectedVirtualSize,
            long nExpectedContainers,
            std::vector<std::string> vRepoDigest,
            std::vector<std::string> vRepoTags,
            std::map<std::string, std::string> mapLabels,
            const std::string &sInfo
        ) {
            this->nI = nI;
            this->sId = sId;
            this->sParentId = sParentId;
            this->nExpectedCreated = nExpectedCreated;
            this->nExpectedSharedSize = nExpectedSharedSize;
            this->nExpectedSize = nExpectedSize;
            this->nExpectedVirtualSize = nExpectedVirtualSize;
            this->nExpectedContainers = nExpectedContainers;
            this->vRepoDigest = vRepoDigest;
            this->vRepoTags = vRepoTags;
            this->mapLabels = mapLabels;
            this->sInfo = sInfo;
        }
        int nI;
        std::string sId;
        std::string sParentId;
        long nExpectedCreated;
        long nExpectedSharedSize;
        long nExpectedSize;
        long nExpectedVirtualSize;
        long nExpectedContainers;
        std::vector<std::string> vRepoDigest;
        std::vector<std::string> vRepoTags;
        std::map<std::string, std::string> mapLabels;
        std::string sInfo;
    };

    std::vector<LTest> tests;
    tests.push_back(
        LTest(
            0, // i
            "sha256:3ec45099d7eb346d6f62a86be84cf1a05c7524f25f4652ee1d1222aa91ac9814", // id
            "sha256:6f5b19f086f3a00d94b62d7d900da87f5dc1d4f56c83ca0404c31bdcc2fba45a", // parent id
            1586246920, // nExpectedCreated
            -1, // nExpectedSharedSize
            566617458, // nExpectedSize
            566617458, // nExpectedVirtualSize
            -1, // nExpectedContainers
            {}, // vRepoDigest
            {"fenugrec/freediag:latest","fenugrec:latest"}, // vRepoTags
            {}, // mapLabels
            "{\"Containers\":-1,\"Created\":1586246920,\"Id\":\"sha256:3ec45099d7eb346d6f62a86be84cf1a05c7524f25f4652ee1d1222aa91ac9814\",\"Labels\":null,\"ParentId\":\"sha256:6f5b19f086f3a00d94b62d7d900da87f5dc1d4f56c83ca0404c31bdcc2fba45a\",\"RepoDigests\":null,\"RepoTags\":[\"fenugrec/freediag:latest\",\"fenugrec:latest\"],\"SharedSize\":-1,\"Size\":566617458,\"VirtualSize\":566617458}"
        )
    );
    tests.push_back(
        LTest(
            1, // i
            "sha256:44a4bacfa057689af0647435ebc2eca624758be14c005bd2bad1d84951debc63", // id
            "sha256:6a71875ae472ae6a2da6481f617362ae44108f2b291f9a42ac24dc1ea535c945", // parent id
            1583992973, // nExpectedCreated
            -1, // nExpectedSharedSize
            435413961, // nExpectedSize
            435413961, // nExpectedVirtualSize
            -1, // nExpectedContainers
            {}, // vRepoDigest
            {"proj1/webapp:latest"}, // vRepoTags
            {}, // mapLabels
            "{\"Containers\":-1,\"Created\":1583992973,\"Id\":\"sha256:44a4bacfa057689af0647435ebc2eca624758be14c005bd2bad1d84951debc63\",\"Labels\":null,\"ParentId\":\"sha256:6a71875ae472ae6a2da6481f617362ae44108f2b291f9a42ac24dc1ea535c945\",\"RepoDigests\":null,\"RepoTags\":[\"proj1/webapp:latest\"],\"SharedSize\":-1,\"Size\":435413961,\"VirtualSize\":435413961}"
        )
    );
    tests.push_back(
        LTest(
            2, // i
            "sha256:35cccfa8625264a0d105f5addfb99f4a5f211858fe39b902a2fcc671b6a751fe", // id
            "sha256:535163c262b3be98d56effecf10d9872cd5abd9d39ff4fc9b479cb32dcc868ac", // parent id
            1583992597, // nExpectedCreated
            -1, // nExpectedSharedSize
            77689932, // nExpectedSize
            77689932, // nExpectedVirtualSize
            -1, // nExpectedContainers
            {}, // vRepoDigest
            {"proj1/backend:latest"}, // vRepoTags
            {}, // mapLabels
            "{\"Containers\":-1,\"Created\":1583992597,\"Id\":\"sha256:35cccfa8625264a0d105f5addfb99f4a5f211858fe39b902a2fcc671b6a751fe\",\"Labels\":null,\"ParentId\":\"sha256:535163c262b3be98d56effecf10d9872cd5abd9d39ff4fc9b479cb32dcc868ac\",\"RepoDigests\":null,\"RepoTags\":[\"proj1/backend:latest\"],\"SharedSize\":-1,\"Size\":77689932,\"VirtualSize\":77689932}"
        )
    );
    tests.push_back(
        LTest(
            3, // i
            "sha256:ee07b1466448b7f4ae417982c97912fd7171d8bfc2e2899d357e2e812c5e70da", // id
            "", // parent id
            1582729858, // nExpectedCreated
            -1, // nExpectedSharedSize
            193446645, // nExpectedSize
            193446645, // nExpectedVirtualSize
            -1, // nExpectedContainers
            {"python@sha256:b7ac0aed085f34498fa7af8b021e204f97d3ecf688855b2b925b5922f1b76f59"}, // vRepoDigest
            {"python:slim"}, // vRepoTags
            {}, // mapLabels
            "{\"Containers\":-1,\"Created\":1582729858,\"Id\":\"sha256:ee07b1466448b7f4ae417982c97912fd7171d8bfc2e2899d357e2e812c5e70da\",\"Labels\":null,\"ParentId\":\"\",\"RepoDigests\":[\"python@sha256:b7ac0aed085f34498fa7af8b021e204f97d3ecf688855b2b925b5922f1b76f59\"],\"RepoTags\":[\"python:slim\"],\"SharedSize\":-1,\"Size\":193446645,\"VirtualSize\":193446645}"
        )
    );
    tests.push_back(
        LTest(
            4, // i
            "sha256:fd78ac5dfca823db5620d6a8dc5e719a4b486969a00dad11204d17da825bb70c", // id
            "", // parent id
            1582157813, // nExpectedCreated
            -1, // nExpectedSharedSize
            129338586, // nExpectedSize
            129338586, // nExpectedVirtualSize
            -1, // nExpectedContainers
            {"mongo-express@sha256:3c02bac3f5ea033e72f72735185de17f31d4ffa51b3c310037d4483e5ec42866"}, // vRepoDigest
            {"mongo-express:latest"}, // vRepoTags
            {}, // mapLabels
            "{\"Containers\":-1,\"Created\":1582157813,\"Id\":\"sha256:fd78ac5dfca823db5620d6a8dc5e719a4b486969a00dad11204d17da825bb70c\",\"Labels\":null,\"ParentId\":\"\",\"RepoDigests\":[\"mongo-express@sha256:3c02bac3f5ea033e72f72735185de17f31d4ffa51b3c310037d4483e5ec42866\"],\"RepoTags\":[\"mongo-express:latest\"],\"SharedSize\":-1,\"Size\":129338586,\"VirtualSize\":129338586}"
        )
    );
    tests.push_back(
        LTest(
            5, // i
            "sha256:839a5e8f04b49f4c6c69f652dc8b139e755089dcb34ac4735e3a8e8bba7500bf", // id
            "", // parent id
            1580675323, // nExpectedCreated
            -1, // nExpectedSharedSize
            912934955, // nExpectedSize
            912934955, // nExpectedVirtualSize
            -1, // nExpectedContainers
            {"node@sha256:82cca33a2e2123ef9a7a93d6ad0d9f93ee2be8f33367b4798a677d3be5493a0b"}, // vRepoDigest
            {"node:12.14-stretch"}, // vRepoTags
            {}, // mapLabels
            "{\"Containers\":-1,\"Created\":1580675323,\"Id\":\"sha256:839a5e8f04b49f4c6c69f652dc8b139e755089dcb34ac4735e3a8e8bba7500bf\",\"Labels\":null,\"ParentId\":\"\",\"RepoDigests\":[\"node@sha256:82cca33a2e2123ef9a7a93d6ad0d9f93ee2be8f33367b4798a677d3be5493a0b\"],\"RepoTags\":[\"node:12.14-stretch\"],\"SharedSize\":-1,\"Size\":912934955,\"VirtualSize\":912934955}"
        )
    );
    tests.push_back(
        LTest(
            6, // i
            "sha256:b3ce5a2100176cb6176b03608a06b1c10033ae03b5f6887fcc9ed53e1815cff1", // id
            "", // parent id
            1577521480, // nExpectedCreated
            -1, // nExpectedSharedSize
            287773299, // nExpectedSize
            287773299, // nExpectedVirtualSize
            -1, // nExpectedContainers
            {"freehackquest/fhq-server@sha256:cb8ab7f048946a0ef07a71d03f8ca92f4dd70056e1c7a2a156bc78d3c03e1a03"}, // vRepoDigest
            {"freehackquest/fhq-server:0.2.25"}, // vRepoTags
            {
                {"maintainer","FreeHackQuest Team <freehackquest@gmail.com>"},
                {"repository","https://github.com/freehackquest/fhq-server"}
            }, // mapLabels
            "{\"Containers\":-1,\"Created\":1577521480,\"Id\":\"sha256:b3ce5a2100176cb6176b03608a06b1c10033ae03b5f6887fcc9ed53e1815cff1\",\"Labels\":{\"maintainer\":\"FreeHackQuest Team <freehackquest@gmail.com>\",\"repository\":\"https://github.com/freehackquest/fhq-server\"},\"ParentId\":\"\",\"RepoDigests\":[\"freehackquest/fhq-server@sha256:cb8ab7f048946a0ef07a71d03f8ca92f4dd70056e1c7a2a156bc78d3c03e1a03\"],\"RepoTags\":[\"freehackquest/fhq-server:0.2.25\"],\"SharedSize\":-1,\"Size\":287773299,\"VirtualSize\":287773299}"
        )
    );
    tests.push_back(
        LTest(
            7, // i
            "sha256:a0e2e64ac939a4f0c9b7aad9fee09f87f7d7f923f50ddcd9ed20f3f229b998f8", // id
            "", // parent id
            1576742208, // nExpectedCreated
            -1, // nExpectedSharedSize
            363718009, // nExpectedSize
            363718009, // nExpectedVirtualSize
            -1, // nExpectedContainers
            {"mongo@sha256:7a1406bfc05547b33a3b7b112eda6346f42ea93ee06b74d30c4c47dfeca0d5f2"}, // vRepoDigest
            {"mongo:latest"}, // vRepoTags
            {}, // mapLabels
            "{\"Containers\":-1,\"Created\":1576742208,\"Id\":\"sha256:a0e2e64ac939a4f0c9b7aad9fee09f87f7d7f923f50ddcd9ed20f3f229b998f8\",\"Labels\":null,\"ParentId\":\"\",\"RepoDigests\":[\"mongo@sha256:7a1406bfc05547b33a3b7b112eda6346f42ea93ee06b74d30c4c47dfeca0d5f2\"],\"RepoTags\":[\"mongo:latest\"],\"SharedSize\":-1,\"Size\":363718009,\"VirtualSize\":363718009}"
        )
    );
    tests.push_back(
        LTest(
            8, // i
            "sha256:89749ed4f17d9e42cfe3182bc08ee5978f82aca2cb21ed09e0ba35dbb46bd875", // id
            "", // parent id
            1574471624, // nExpectedCreated
            -1, // nExpectedSharedSize
            125970238, // nExpectedSize
            125970238, // nExpectedVirtualSize
            -1, // nExpectedContainers
            {"nginx@sha256:8e05c1256640382a6ea4452fb90c031ce3938315363a5fecc9bda792ee700f71"}, // vRepoDigest
            {"nginx:1.16"}, // vRepoTags
            {{"maintainer","NGINX Docker Maintainers <docker-maint@nginx.com>"}}, // mapLabels
            "{\"Containers\":-1,\"Created\":1574471624,\"Id\":\"sha256:89749ed4f17d9e42cfe3182bc08ee5978f82aca2cb21ed09e0ba35dbb46bd875\",\"Labels\":{\"maintainer\":\"NGINX Docker Maintainers <docker-maint@nginx.com>\"},\"ParentId\":\"\",\"RepoDigests\":[\"nginx@sha256:8e05c1256640382a6ea4452fb90c031ce3938315363a5fecc9bda792ee700f71\"],\"RepoTags\":[\"nginx:1.16\"],\"SharedSize\":-1,\"Size\":125970238,\"VirtualSize\":125970238}"
        )
    );
    tests.push_back(
        LTest(
            9, // i
            "sha256:ec8e8e69afc26a808c65e324ce9c7f791fa8cc8d310b9112118e4ae047be7f04", // id
            "", // parent id
            1571767425, // nExpectedCreated
            -1, // nExpectedSharedSize
            695312937, // nExpectedSize
            695312937, // nExpectedVirtualSize
            -1, // nExpectedContainers
            {"freehackquest/debian-10-for-cpp-common@sha256:3dc2b3712e16717714ba6fc0afa40ed2524bdc5a183ae774b5386ad842544432"}, // vRepoDigest
            {"freehackquest/debian-10-for-cpp-common:latest"}, // vRepoTags
            {
                {"maintainer","FreeHackQuest Team <freehackquest@gmail.com>"},
                {"repository","https://github.com/freehackquest/debian-10-cpp-common"}
            }, // mapLabels
            "{\"Containers\":-1,\"Created\":1571767425,\"Id\":\"sha256:ec8e8e69afc26a808c65e324ce9c7f791fa8cc8d310b9112118e4ae047be7f04\",\"Labels\":{\"maintainer\":\"FreeHackQuest Team <freehackquest@gmail.com>\",\"repository\":\"https://github.com/freehackquest/debian-10-cpp-common\"},\"ParentId\":\"\",\"RepoDigests\":[\"freehackquest/debian-10-for-cpp-common@sha256:3dc2b3712e16717714ba6fc0afa40ed2524bdc5a183ae774b5386ad842544432\"],\"RepoTags\":[\"freehackquest/debian-10-for-cpp-common:latest\"],\"SharedSize\":-1,\"Size\":695312937,\"VirtualSize\":695312937}"
        )
    );
    tests.push_back(
        LTest(
            10, // i
            "sha256:bcf1f70fba7aee3834626518c0c27e310d4bdfd0b2fb90380b7416197c102221", // id
            "", // parent id
            1571766839, // nExpectedCreated
            -1, // nExpectedSharedSize
            475393423, // nExpectedSize
            475393423, // nExpectedVirtualSize
            -1, // nExpectedContainers
            {"freehackquest/debian-10-for-cpp-build@sha256:909fb2074a96d2d0511f4e0c900546f33fbaa17e016aa043fe1ceb3a2fa6d515"}, // vRepoDigest
            {"freehackquest/debian-10-for-cpp-build:latest"}, // vRepoTags
            {
                {"maintainer","FreeHackQuest Team <freehackquest@gmail.com>"},
                {"repository","https://github.com/freehackquest/debian-10-cpp-build"}
            }, // mapLabels
            "{\"Containers\":-1,\"Created\":1571766839,\"Id\":\"sha256:bcf1f70fba7aee3834626518c0c27e310d4bdfd0b2fb90380b7416197c102221\",\"Labels\":{\"maintainer\":\"FreeHackQuest Team <freehackquest@gmail.com>\",\"repository\":\"https://github.com/freehackquest/debian-10-cpp-build\"},\"ParentId\":\"\",\"RepoDigests\":[\"freehackquest/debian-10-for-cpp-build@sha256:909fb2074a96d2d0511f4e0c900546f33fbaa17e016aa043fe1ceb3a2fa6d515\"],\"RepoTags\":[\"freehackquest/debian-10-for-cpp-build:latest\"],\"SharedSize\":-1,\"Size\":475393423,\"VirtualSize\":475393423}"
        )
    );
    tests.push_back(
        LTest(
            11, // i
            "sha256:c09d2530df0139d4e3b7aca664560610948601fe743897e3fc6b770b09350274", // id
            "", // parent id
            1571300275, // nExpectedCreated
            -1, // nExpectedSharedSize
            91150010, // nExpectedSize
            91150010, // nExpectedVirtualSize
            -1, // nExpectedContainers
            {"haproxy@sha256:286627c8bf344fdf9e12ecb391ce2c26a85ac2cb642221a1744f7387536e8398"}, // vRepoDigest
            {"haproxy:2.0"}, // vRepoTags
            {}, // mapLabels
            "{\"Containers\":-1,\"Created\":1571300275,\"Id\":\"sha256:c09d2530df0139d4e3b7aca664560610948601fe743897e3fc6b770b09350274\",\"Labels\":null,\"ParentId\":\"\",\"RepoDigests\":[\"haproxy@sha256:286627c8bf344fdf9e12ecb391ce2c26a85ac2cb642221a1744f7387536e8398\"],\"RepoTags\":[\"haproxy:2.0\"],\"SharedSize\":-1,\"Size\":91150010,\"VirtualSize\":91150010}"
        )
    );
    tests.push_back(
        LTest(
            12, // i
            "sha256:de25a81a5a0b6ff26c82bab404fff5de5bf4bbbc48c833412fb3706077d31134", // id
            "", // parent id
            1571282584, // nExpectedCreated
            -1, // nExpectedSharedSize
            98219036, // nExpectedSize
            98219036, // nExpectedVirtualSize
            -1, // nExpectedContainers
            {"redis@sha256:fe80393a67c7058590ca6b6903f64e35b50fa411b0496f604a85c526fb5bd2d2"}, // vRepoDigest
            {"redis:latest"}, // vRepoTags
            {}, // mapLabels
            "{\"Containers\":-1,\"Created\":1571282584,\"Id\":\"sha256:de25a81a5a0b6ff26c82bab404fff5de5bf4bbbc48c833412fb3706077d31134\",\"Labels\":null,\"ParentId\":\"\",\"RepoDigests\":[\"redis@sha256:fe80393a67c7058590ca6b6903f64e35b50fa411b0496f604a85c526fb5bd2d2\"],\"RepoTags\":[\"redis:latest\"],\"SharedSize\":-1,\"Size\":98219036,\"VirtualSize\":98219036}"
        )
    );
    tests.push_back(
        LTest(
            13, // i
            "sha256:8e9f8546050da8aae393a41d65ad37166b4f0d8131d627a520c0f0451742e9d6", // id
            "", // parent id
            1571268359, // nExpectedCreated
            -1, // nExpectedSharedSize
            114050530, // nExpectedSize
            114050530, // nExpectedVirtualSize
            -1, // nExpectedContainers
            {"debian@sha256:41f76363fd83982e14f7644486e1fb04812b3894aa4e396137c3435eaf05de88"}, // vRepoDigest
            {"debian:10"}, // vRepoTags
            {}, // mapLabels
            "{\"Containers\":-1,\"Created\":1571268359,\"Id\":\"sha256:8e9f8546050da8aae393a41d65ad37166b4f0d8131d627a520c0f0451742e9d6\",\"Labels\":null,\"ParentId\":\"\",\"RepoDigests\":[\"debian@sha256:41f76363fd83982e14f7644486e1fb04812b3894aa4e396137c3435eaf05de88\"],\"RepoTags\":[\"debian:10\"],\"SharedSize\":-1,\"Size\":114050530,\"VirtualSize\":114050530}"
        )
    );
    tests.push_back(
        LTest(
            14, // i
            "sha256:ee2097dc5afabe77aee5d1872e2e838848659bb1ecfef0a78bd824b6e3feb159", // id
            "", // parent id
            1568311217, // nExpectedCreated
            -1, // nExpectedSharedSize
            229926104, // nExpectedSize
            229926104, // nExpectedVirtualSize
            -1, // nExpectedContainers
            {"postgres@sha256:9ee979b15082e0bd9526fde1717ffea0059e3bad936d5be9e9e5f3404f5d9375"}, // vRepoDigest
            {"postgres:10"}, // vRepoTags
            {}, // mapLabels
            "{\"Containers\":-1,\"Created\":1568311217,\"Id\":\"sha256:ee2097dc5afabe77aee5d1872e2e838848659bb1ecfef0a78bd824b6e3feb159\",\"Labels\":null,\"ParentId\":\"\",\"RepoDigests\":[\"postgres@sha256:9ee979b15082e0bd9526fde1717ffea0059e3bad936d5be9e9e5f3404f5d9375\"],\"RepoTags\":[\"postgres:10\"],\"SharedSize\":-1,\"Size\":229926104,\"VirtualSize\":229926104}"
        )
    );
    tests.push_back(
        LTest(
            15, // i
            "sha256:00bf7fdd8baf2ba6f0918e1f48415b2a4a1a616806e7cf32527a749dd2ce4b2c", // id
            "", // parent id
            1562707312, // nExpectedCreated
            -1, // nExpectedSharedSize
            114038881, // nExpectedSize
            114038881, // nExpectedVirtualSize
            -1, // nExpectedContainers
            {"debian@sha256:903779f30a7ee46937bfb21406f125d5fdace4178074e1cc71c49039ebf7f48f"}, // vRepoDigest
            {"debian:10.0"}, // vRepoTags
            {}, // mapLabels
            "{\"Containers\":-1,\"Created\":1562707312,\"Id\":\"sha256:00bf7fdd8baf2ba6f0918e1f48415b2a4a1a616806e7cf32527a749dd2ce4b2c\",\"Labels\":null,\"ParentId\":\"\",\"RepoDigests\":[\"debian@sha256:903779f30a7ee46937bfb21406f125d5fdace4178074e1cc71c49039ebf7f48f\"],\"RepoTags\":[\"debian:10.0\"],\"SharedSize\":-1,\"Size\":114038881,\"VirtualSize\":114038881}"
        )
    );
    tests.push_back(
        LTest(
            16, // i
            "sha256:f391dabf9dce53bfc184823f18b7703db8dfead7f25e5b376865e690433bec78", // id
            "", // parent id
            1557539574, // nExpectedCreated
            -1, // nExpectedSharedSize
            77689522, // nExpectedSize
            77689522, // nExpectedVirtualSize
            -1, // nExpectedContainers
            {"node@sha256:2ab3d9a1bac67c9b4202b774664adaa94d2f1e426d8d28e07bf8979df61c8694"}, // vRepoDigest
            {"node:12.2.0-alpine"}, // vRepoTags
            {}, // mapLabels
            "{\"Containers\":-1,\"Created\":1557539574,\"Id\":\"sha256:f391dabf9dce53bfc184823f18b7703db8dfead7f25e5b376865e690433bec78\",\"Labels\":null,\"ParentId\":\"\",\"RepoDigests\":[\"node@sha256:2ab3d9a1bac67c9b4202b774664adaa94d2f1e426d8d28e07bf8979df61c8694\"],\"RepoTags\":[\"node:12.2.0-alpine\"],\"SharedSize\":-1,\"Size\":77689522,\"VirtualSize\":77689522}"
        )
    );
    tests.push_back(
        LTest(
            17, // i
            "sha256:d8233ab899d419c58cf3634c0df54ff5d8acc28f8173f09c21df4a07229e1205", // id
            "", // parent id
            1550189977, // nExpectedCreated
            -1, // nExpectedSharedSize
            1199417, // nExpectedSize
            1199417, // nExpectedVirtualSize
            -1, // nExpectedContainers
            {"busybox@sha256:061ca9704a714ee3e8b80523ec720c64f6209ad3f97c0ff7cb9ec7d19f15149f"}, // vRepoDigest
            {"busybox:latest"}, // vRepoTags
            {}, // mapLabels
            "{\"Containers\":-1,\"Created\":1550189977,\"Id\":\"sha256:d8233ab899d419c58cf3634c0df54ff5d8acc28f8173f09c21df4a07229e1205\",\"Labels\":null,\"ParentId\":\"\",\"RepoDigests\":[\"busybox@sha256:061ca9704a714ee3e8b80523ec720c64f6209ad3f97c0ff7cb9ec7d19f15149f\"],\"RepoTags\":[\"busybox:latest\"],\"SharedSize\":-1,\"Size\":1199417,\"VirtualSize\":1199417}"
        )
    );
    tests.push_back(
        LTest(
            18, // i
            "sha256:1e9efd9f677994fca9f933621b4b0a35ce4c45faac406f7e1baa9b3d395c6ae9", // id
            "", // parent id
            1546058325, // nExpectedCreated
            -1, // nExpectedSharedSize
            377753824, // nExpectedSize
            377753824, // nExpectedVirtualSize
            -1, // nExpectedContainers
            {"php@sha256:b1f42a16f6765cb685973d8ea0776c886dc6aca5fb14b059bb4ea5d5bb1a9896"}, // vRepoDigest
            {"php:7.3.0-apache"}, // vRepoTags
            {}, // mapLabels
            "{\"Containers\":-1,\"Created\":1546058325,\"Id\":\"sha256:1e9efd9f677994fca9f933621b4b0a35ce4c45faac406f7e1baa9b3d395c6ae9\",\"Labels\":null,\"ParentId\":\"\",\"RepoDigests\":[\"php@sha256:b1f42a16f6765cb685973d8ea0776c886dc6aca5fb14b059bb4ea5d5bb1a9896\"],\"RepoTags\":[\"php:7.3.0-apache\"],\"SharedSize\":-1,\"Size\":377753824,\"VirtualSize\":377753824}"
        )
    );
    tests.push_back(
        LTest(
            19, // i
            "sha256:ae6b78bedf88330a5e5392164f40d28ed8a38120b142905d30b652ebffece10e", // id
            "", // parent id
            1542330860, // nExpectedCreated
            -1, // nExpectedSharedSize
            372110967, // nExpectedSize
            372110967, // nExpectedVirtualSize
            -1, // nExpectedContainers
            {"mysql@sha256:c23e9bfe66eeffc990cf6bce4bb0e9c5c85eb908170f3b3dde3e9a12c5a91689"}, // vRepoDigest
            {"mysql:5.7"}, // vRepoTags
            {}, // mapLabels
            "{\"Containers\":-1,\"Created\":1542330860,\"Id\":\"sha256:ae6b78bedf88330a5e5392164f40d28ed8a38120b142905d30b652ebffece10e\",\"Labels\":null,\"ParentId\":\"\",\"RepoDigests\":[\"mysql@sha256:c23e9bfe66eeffc990cf6bce4bb0e9c5c85eb908170f3b3dde3e9a12c5a91689\"],\"RepoTags\":[\"mysql:5.7\"],\"SharedSize\":-1,\"Size\":372110967,\"VirtualSize\":372110967}"
        )
    );
    tests.push_back(
        LTest(
            20, // i
            "sha256:be2868bebaba284d8c3f36ba7167b5e3318cab1c0d09734a1598ace3a9a96866", // id
            "", // parent id
            1539645861, // nExpectedCreated
            -1, // nExpectedSharedSize
            100576015, // nExpectedSize
            100576015, // nExpectedVirtualSize
            -1, // nExpectedContainers
            {"debian@sha256:802706fa62e75c96fff96ada0e8ca11f570895ae2e9ba4a9d409981750ca544c"}, // vRepoDigest
            {"debian:9.5"}, // vRepoTags
            {}, // mapLabels
            "{\"Containers\":-1,\"Created\":1539645861,\"Id\":\"sha256:be2868bebaba284d8c3f36ba7167b5e3318cab1c0d09734a1598ace3a9a96866\",\"Labels\":null,\"ParentId\":\"\",\"RepoDigests\":[\"debian@sha256:802706fa62e75c96fff96ada0e8ca11f570895ae2e9ba4a9d409981750ca544c\"],\"RepoTags\":[\"debian:9.5\"],\"SharedSize\":-1,\"Size\":100576015,\"VirtualSize\":100576015}"
        )
    );
    tests.push_back(
        LTest(
            21, // i
            "sha256:34ea7509dcad10aa92310f2b41e3afbabed0811ee3a902d6d49cb90f075fe444", // id
            "", // parent id
            1536704379, // nExpectedCreated
            -1, // nExpectedSharedSize
            4206620, // nExpectedSize
            4206620, // nExpectedVirtualSize
            2, // nExpectedContainers
            {"alpine@sha256:a52b4edb6240d1534d54ee488d7cf15b3778a5cfd0e4161d426c550487cddc5d"}, // vRepoDigest
            {"alpine:3.7"}, // vRepoTags
            {}, // mapLabels
            "{\"Containers\":2,\"Created\":1536704379,\"Id\":\"sha256:34ea7509dcad10aa92310f2b41e3afbabed0811ee3a902d6d49cb90f075fe444\",\"Labels\":null,\"ParentId\":\"\",\"RepoDigests\":[\"alpine@sha256:a52b4edb6240d1534d54ee488d7cf15b3778a5cfd0e4161d426c550487cddc5d\"],\"RepoTags\":[\"alpine:3.7\"],\"SharedSize\":-1,\"Size\":4206620,\"VirtualSize\":4206620}"
        )
    );

    for (int i = 0; i < tests.size(); i++) {
        std::string sTextN = "test N = " + std::to_string(i);
        LTest test = tests[i];
        compareN(bTestSuccess, sTextN + ", i", i, test.nI);
        if (!nlohmann::json::accept(test.sInfo)) {
            bTestSuccess = false;
            WsjcppLog::err(TAG, "Wrong json for " + sTextN);
        } else {
            nlohmann::json jsonImage = nlohmann::json::parse(test.sInfo);
            WsjcppDockerImage img;
            if (!img.fillFromJson(jsonImage)) {
                bTestSuccess = false;
                WsjcppLog::err(TAG, "Invalid data format in json " + sTextN);
            } else {
                compareS(bTestSuccess, sTextN + ", id", img.getId(), test.sId);
                compareS(bTestSuccess, sTextN + ", parentId", img.getParentId(), test.sParentId);
                compareN(bTestSuccess, sTextN + ", created", img.getCreated(), test.nExpectedCreated);
                compareN(bTestSuccess, sTextN + ", shared size", img.getSharedSize(), test.nExpectedSharedSize);
                compareN(bTestSuccess, sTextN + ", size", img.getSize(), test.nExpectedSize);
                compareN(bTestSuccess, sTextN + ", virtual size", img.getVirtualSize(), test.nExpectedVirtualSize);
                compareN(bTestSuccess, sTextN + ", containers", img.getContainers(), test.nExpectedContainers);
                std::vector<std::string> vRepoDigest = img.getRepoDigests();
                compareN(bTestSuccess, sTextN + ", repoDigest size", vRepoDigest.size(), test.vRepoDigest.size());

                if (vRepoDigest.size() == test.vRepoDigest.size()) {
                    for (int x = 0; x < test.vRepoDigest.size(); x++) {
                        compareS(bTestSuccess, sTextN + ", repoDigest X =" + std::to_string(x), vRepoDigest[x], test.vRepoDigest[x]);
                    }
                }
                
                std::vector<std::string> vRepoTags = img.getRepoTags();
                compareN(bTestSuccess, sTextN + ", repoTags size", vRepoTags.size(), test.vRepoTags.size());

                if (vRepoTags.size() == test.vRepoTags.size()) {
                    for (int x = 0; x < test.vRepoTags.size(); x++) {
                        compareS(bTestSuccess, sTextN + ", repoTags X =" + std::to_string(x), vRepoTags[x], test.vRepoTags[x]);
                    }
                }

                std::map<std::string, std::string> mapLabels = img.getLabels();
                compareN(bTestSuccess, sTextN + ", labels size", mapLabels.size(), test.mapLabels.size());
                std::map<std::string, std::string>::iterator it;
                for (it = test.mapLabels.begin(); it != test.mapLabels.end(); ++it) {
                    std::string sExpectedKey = it->first;
                    std::string sExpectedValue = it->second;

                    std::map<std::string, std::string>::iterator it2 = mapLabels.find(sExpectedKey);
                    if (it2 != mapLabels.end()) {
                        std::string sValue = it2->second;
                        compareS(bTestSuccess, sTextN + ", labels [" + sExpectedKey + "] ", sValue, sExpectedValue);
                    } else {
                        bTestSuccess = false;
                        WsjcppLog::err(TAG, "{" + sTextN + "}, Expected key '" + sExpectedKey + "', but it does not found");
                    }

                    // test.mapLabels[sKey]
                }
                 /*
                    std::map<std::string, std::string> getLabels();
                */
            }
            
        }
    }
    
    return bTestSuccess;
}


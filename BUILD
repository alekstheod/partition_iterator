cc_library(
    name = "partition_iterator",
    hdrs = glob(["include/*.hpp"]),
    includes = ["include"],
    strip_include_prefix = "include",
    visibility = [
        "//visibility:public",
    ],
)

cc_test(
    name = "partition_iterator_ut",
    srcs = glob([
        "test/*.cpp",
        "test/*.hpp",
    ]),
    deps = [
        ":partition_iterator",
        "@catch2",
    ],
)

cc_binary(
    name = "sample",
    srcs = ["sample/sample.cpp"],
    deps = [":partition_iterator"],
)

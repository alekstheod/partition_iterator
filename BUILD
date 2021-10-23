cc_library(
	name = "partition_iterator",
	includes = ["include"],
	strip_include_prefix = "include",
	hdrs = glob(["include/*.hpp"]),
	visibility = [
		"//visibility:public",
	],
)

cc_test(
	name = "partition_iterator_ut",
	srcs = glob(["test/*.cpp", "test/*.hpp"]),
	deps =  [":partition_iterator"],
)

cc_binary(
	name = "sample",
	srcs = ["sample/sample.cpp"],
	deps = [":partition_iterator"],
)

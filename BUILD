licenses(["notice"])

exports_files([
    "LICENSE",
    "NOTICE",
])

COPTS = [
    "-UNDEBUG",
    "-faligned-new",
]

LINKOPTS = [
    "-lpthread",
    "-lnuma",
]

LIBS = [
    "@libprim//:prim",
    "@librnd//:rnd",
    "@zlib//:zlib",
]

cc_library(
    name = "des",
    srcs = glob(
        ["src/**/*.cc"],
        exclude = ["src/**/*_TEST*"],
    ),
    hdrs = glob(
        [
            "src/**/*.h",
            "src/**/*.tcc",
        ],
        exclude = ["src/**/*_TEST*"],
    ),
    copts = COPTS,
    includes = [
        "src",
    ],
    linkopts = LINKOPTS,
    visibility = ["//visibility:public"],
    deps = LIBS,
    alwayslink = 1,
)

cc_library(
    name = "test_lib",
    testonly = 1,
    srcs = glob([
        "src/**/*_TEST*.cc",
    ]),
    hdrs = glob([
        "src/**/*_TEST*.h",
        "src/**/*_TEST*.tcc",
    ]),
    copts = COPTS,
    visibility = ["//visibility:private"],
    deps = [
        ":des",
        "@googletest//:gtest_main",
    ] + LIBS,
    alwayslink = 1,
)

cc_test(
    name = "des_test",
    args = [
        "--gtest_color=yes",
    ],
    copts = COPTS,
    linkopts = LINKOPTS,
    visibility = ["//visibility:public"],
    deps = [
        ":test_lib",
    ] + LIBS,
)

genrule(
    name = "lint",
    srcs = glob([
        "src/**/*.cc",
    ]) + glob([
        "src/**/*.h",
        "src/**/*.tcc",
    ]),
    outs = ["linted"],
    cmd = """
    python $(location @cpplint//:cpplint) \
      --root=$$(pwd)/src \
      --headers=h,tcc \
      --extensions=cc,h,tcc \
      --quiet $(SRCS) > $@
    echo // $$(date) > $@
    """,
    tools = [
        "@cpplint",
    ],
    visibility = ["//visibility:public"],
)

genrule(
    name = "format_check",
    srcs = glob([
        "src/**/*.cc",
        "src/**/*.h",
        "src/**/*.tcc",
    ]),
    outs = ["format_checked"],
    cmd = """
    cp $(location @clang_format//file) .clang-format
    clang-format --style=file --dry-run --Werror $(SRCS)
    echo // $$(date) > $@
    """,
    tools = [
        "@clang_format//file",
    ],
    visibility = ["//visibility:public"],
)

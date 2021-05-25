// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "ImageMagick",
    platforms: [
        .iOS(.v14)
    ],
    products: [
        .library(
            name: "ImageMagick",
            targets: ["ImageMagick"]
        ),
        .library(
            name: "ImageMagick7",
            targets: ["ImageMagick7"]
        ),
    ],
    dependencies: [
//        .package(name: "ImageMagick7Remote", url: "https://github.com/dmedynskyi-skelia/ImageMagick7Remote.git", from: "1.0.0"),
    ],
    targets: [
        .binaryTarget(name: "ImageMagick7", path: "Frameworks/ImageMagickFramework.xcframework"),
        .target(
            name: "ImageMagick",
            dependencies: [
                "ImageMagick7"
            ],
            path: "Sources"
        )
    ]
)

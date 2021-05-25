//  ImageMagick.swift
//  
//
//
//  
//
#if os(iOS)
import Combine
import Foundation
//import ImageMagick7Remote
import ImageMagick7

public final class ImageMagick: NSObject {
    static var isGenesis = false
    let magicWand = NewMagickWand()
    public override init() {
        super.init()
        if !Self.isGenesis {
            Self.isGenesis = true
            MagickWandGenesis()
        }
    }
    deinit {
        DestroyMagickWand(magicWand)
    }

    public func magicWand(at wandPoints: [CGPoint], image: UIImage, wandColorTolerance: Double, wandColor: UIColor = .clear) -> UIImage? {
        return image.pngData().flatMap {magicWand(at: wandPoints, imageData: $0, wandColorTolerance: wandColorTolerance, wandColor: wandColor)}.flatMap {UIImage(data: $0, scale: image.scale) }
    }

    func magicWand(at wandPoints: [CGPoint], imageData: Data, wandColorTolerance: Double, wandColor: UIColor?) -> Data? {
        let scale: CGFloat = 1.0
        let replacementWandColor = wandColor ?? .clear
        let fc_wand = NewPixelWand()
        let bc_wand = NewPixelWand()
        let colorRef = replacementWandColor.cgColor

        guard var components = colorRef.components?.compactMap({$0 * 255.0}), components.count <= 4 else { return nil }
        for _ in components.underestimatedCount..<4 {
            components.append(0.0)
        }
        guard PixelSetColor(fc_wand, "rgba(\(components.map {"\($0)"}.joined(separator: ",")))".utf8.map {Int8($0)}) == MagickBooleanType(rawValue: 1) else { return nil }
        ClearMagickWand(magicWand)
        guard MagickReadImageBlob(magicWand, Array(imageData), imageData.count) == MagickBooleanType(rawValue: 1) else { return nil }
        let scaledPoints = wandPoints
            .map {CGPoint(x: $0.x * scale, y: $0.y * scale)}
        for point in scaledPoints {
            MagickGetImagePixelColor(magicWand, Int(point.x), Int(point.y), bc_wand)
            guard MagickFloodfillPaintImage(magicWand, fc_wand, wandColorTolerance, bc_wand, Int(point.x), Int(point.y), MagickBooleanType(rawValue: 0)) != MagickBooleanType(rawValue: 0) else { break }
        }
        var imageDataSize = 0

        let myImage = MagickGetImageBlob(magicWand, &imageDataSize)
        let newImageData = myImage.map {Data(bytes: $0, count: imageDataSize)}
        free(myImage)

        DestroyPixelWand(fc_wand)
        DestroyPixelWand(bc_wand)
        ClearMagickWand(magicWand)
        return newImageData
    }
}
#endif

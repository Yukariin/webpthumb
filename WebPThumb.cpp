#include <QFile>
#include <QImage>
#include <webp/decode.h>

#include "WebPThumb.h"

extern "C"
{
    Q_DECL_EXPORT ThumbCreator *new_creator()
    {
        return new WebPThumb();
    }
};

bool WebPThumb::create(const QString &path, int width, int height, QImage &img)
{
    Q_UNUSED(width)
    Q_UNUSED(height)

    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QByteArray data = file.readAll();

    WebPBitstreamFeatures features;
    VP8StatusCode code = WebPGetFeatures(reinterpret_cast<const uint8_t*>(data.constData()), data.size(), &features);
    if (code != VP8_STATUS_OK)
        return false;

    QImage result(features.width, features.height, QImage::Format_ARGB32);
    uint8_t *output = result.bits();
    size_t output_size = result.byteCount();

#if Q_BYTE_ORDER == Q_LITTLE_ENDIAN
    if (!WebPDecodeBGRAInto(reinterpret_cast<const uint8_t*>(data.constData()), data.size(),
                            output, output_size, result.bytesPerLine()))
#else
    if (!WebPDecodeARGBInto(reinterpret_cast<const uint8_t*>(data.constData()), data.size(),
                            output, output_size, result.bytesPerLine()))
#endif
        return false;

    img = result;
    return true;
}

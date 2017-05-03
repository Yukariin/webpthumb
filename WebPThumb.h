#ifndef _WEBPTHUMB_H_
#define _WEBPTHUMB_H_

#include <kio/thumbcreator.h>

class WebPThumb : public ThumbCreator
{
public:
    bool create(const QString &path, int width, int height, QImage &img) override;
};

#endif //_WEBPTHUMB_H_

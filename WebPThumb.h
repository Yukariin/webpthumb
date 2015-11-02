#ifndef WEBPTHUMB_WEBPTHUMB_H
#define WEBPTHUMB_WEBPTHUMB_H

#include <kio/thumbcreator.h>

class WebPThumb : public ThumbCreator
{
public:
    virtual bool create(const QString &path, int width, int height, QImage &img);
};


#endif //WEBPTHUMB_WEBPTHUMB_H

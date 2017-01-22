#ifndef _WEBPTHUMB_H_
#define _WEBPTHUMB_H_

#include <kio/thumbcreator.h>

class WebPThumb : public ThumbCreator
{
public:
    virtual bool create(const QString &path, int width, int height, QImage &img);
};

#endif //_WEBPTHUMB_H_

#ifndef __ITEM_H__
#define __ITEM_H__

class Item {
    protected:

    public:
    virtual ~Item() = default;

    virtual void applyBuff() = 0;
    
};

#endif //__ITEM_H__
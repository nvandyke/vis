#ifndef VECTORS
#define VECTORS

class vector2 {
public:
    float x, y;
    vector2(float xVal = 0.0, float yVal = 0.0) {
        x = xVal;
        y = yVal;
    };

    vector2 operator+(vector2 rhs) {
        vector2 retVal(x+rhs.x, y+rhs.y);
        return retVal;
    };

    vector2 operator-(vector2 rhs) {
        vector2 retVal(x-rhs.x, y-rhs.y);
        return retVal;
    };
};


class vector3 : public vector2 {
public:
    float  z;
    vector3(float xVal = 0.0, float yVal = 0.0, float zVal = 0.0) {
        x = xVal;
        y = yVal;
        z = zVal;
    };

    vector3 operator+(vector3 rhs) {
        vector3 retVal(x+rhs.x, y+rhs.y, z+rhs.z);
        return retVal;
    };

    vector3 operator-(vector3 rhs) {
        vector3 retVal(x-rhs.x, y-rhs.y, z-rhs.z);
        return retVal;
    };
};


class matrix3 {
public:
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    matrix3(float xxVal = 0.0, float xyVal = 0.0, float xzVal = 0.0,
            float yxVal = 0.0, float yyVal = 0.0, float yzVal = 0.0,
            float zxVal = 0.0, float zyVal = 0.0, float zzVal = 0.0) {
        xx = xxVal;
        xy = xyVal;
        xz = xzVal;
        yx = yxVal;
        yy = yyVal;
        yz = yzVal;
        zx = zxVal;
        zy = zyVal;
        zz = zzVal;
    };

    vector3 operator*(vector3 v) {
        float xVal = xx*v.x + xy*v.y + xz*v.z;
        float yVal = yx*v.x + yy*v.y + yz*v.z;
        float zVal = zx*v.x + zy*v.y + zz*v.z;
        vector3 retVal(xVal,yVal,zVal);
        return retVal;
    };
};


#endif

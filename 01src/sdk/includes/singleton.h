#ifndef SINGLETON_H
#define SINGLETON_H

#include <QMutex>

#if 0
// Lazy Singleton
class LazySingleton
{
public:
    // 返回引用避免指针可能会被外部调用者delete的隐患
    // 延迟初始化（Lazy initalization）
    static LazySingleton &getInstance() {
        if (0 == instance) {
            instance = new LazySingleton;
        }

        return *instance;
    }

    // 返回指针，方便调用
    static LazySingleton *getInstancePtr() {
        if (0 == instance) {
            instance = new LazySingleton;
        }

        return instance;
    }

private:
    LazySingleton(){}
    ~LazySingleton(){}

    // 避免通过拷贝函数或赋值操作符生成新实例
    LazySingleton(const LazySingleton &);
    LazySingleton &operator = (const LazySingleton &);

private:
    static LazySingleton *instance;
};
LazySingleton *LazySingleton::instance = 0;


// Eager Singleton
class EagerSingleton
{
public:
    static EagerSingleton &getInstance() {
        return instance;
    }

private:
    EagerSingleton(){}  // {}
    ~EagerSingleton(){}

    EagerSingleton(const EagerSingleton &);
    EagerSingleton &operator = (const EagerSingleton &);

private:
    // 在main()函数之前初始化，无线程安全问题
    static EagerSingleton instance;
};
EagerSingleton EagerSingleton::instance;


// Meyers Singleton
class MeyersSingleton
{
public:
    static MeyersSingleton &getInstance() {
        static MeyersSingleton instance;
        return instance;
    }

private:
    MeyersSingleton();
    ~MeyersSingleton();

    MeyersSingleton(const MeyersSingleton &);
    MeyersSingleton &operator = (const MeyersSingleton &);
};


// DCLP(Double-Checked Locking Pattern/双检测锁模式) Singleton
class DCLPSingleton
{
public:
    static DCLPSingleton &getInstance() {
        QMutex lock;
        lock.lock();
        if (0 == instance) {
            instance = new DCLPSingleton;
        }

        return *instance;
    }

private:
    DCLPSingleton();
    ~DCLPSingleton();

    DCLPSingleton(const DCLPSingleton &);
    DCLPSingleton &operator = (const DCLPSingleton &);

private:
    static DCLPSingleton *instance;
};
#endif


// As template
template <typename T>
class Singleton
{
public:
    Singleton() {
        instance = (T *)this;
    }
    ~Singleton() {
        instance = 0;
    }

    static T &getInstance() {
        if (0 == instance) {
            instance = new T;
        }

        return *instance;
    }

    static T *getInstancePtr() {
        if (0 == instance) {
            instance = new T;
        }

        return instance;
    }

private:
    Singleton(const Singleton &);
    Singleton &operator = (const Singleton &);    

private:
    static T *instance;
};
template<typename T>
T *Singleton<T>::instance = 0;

#endif // SINGLETON_H

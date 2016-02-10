#ifndef __UTILS_LAZY_HPP__
#define __UTILS_LAZY_HPP__


namespace utils {
namespace lazy {

template<typename T>
class Lazy
{
public:
    Lazy() : pointer_(nullptr)  {                  }
    virtual ~Lazy()             { delete pointer_; }
    const T *operator->() const { return   eval(); }
    /* */ T *operator->()       { return   eval(); }
    const T& operator()() const { return  *eval(); }
    /* */ T& operator()()       { return  *eval(); }

    /**
     * May be called manually.  If there's a chance for the init()
     * method to fail, you should check the result of eval().  If it's
     * not NULL, you're good to go.  Otherwise it's unsafe to use this
     * instance.
     *
     * NB: This method is *NOT* thread-safe.
     */
    inline T *eval() const
    {
        if (pointer_ == nullptr)
        {
            pointer_ = init();
        }
        return pointer_;
    }

    const T *pointer() const
    {
        return pointer_;
    }

protected:
    virtual T *init() const = 0;

private:
    mutable T *pointer_;
};

} // namespaze lazy
} // namespace utils

# endif // __UTILS_LAZY_HPP__

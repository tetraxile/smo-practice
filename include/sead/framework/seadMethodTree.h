#pragma once

#include <sead/container/seadTreeNode.h>
#include <sead/heap/seadDisposer.h>
#include <sead/prim/seadBitFlag.h>
#include <sead/prim/seadDelegate.h>
#include <sead/prim/seadNamable.h>
#include <sead/prim/seadRuntimeTypeInfo.h>
#include <sead/prim/seadStorageFor.h>

namespace sead {
class CriticalSection;

template <typename T, typename U>
class IDelegate2;

class MethodTreeNode : public IDisposer, public TTreeNode<MethodTreeNode*>, public INamable
{
    SEAD_RTTI_BASE(MethodTreeNode)

public:
    enum PauseFlag
    {
        cPause_None = 0,
        cPause_Self = 1,
        cPause_Child = 2,
        cPause_Both = 3,
    };

    using PauseEventDelegate = IDelegate2<MethodTreeNode*, PauseFlag>;

    // NON_MATCHING: stores for mPauseFlag, mPauseEventDelegate, mUserID
    explicit MethodTreeNode(CriticalSection* cs) : TTreeNode(this)
    {
        mCriticalSection = cs;
        mPauseEventDelegate = nullptr;
        mUserID = nullptr;
        mDelegateHolder.construct(sead::Delegate<MethodTreeNode>());
        setPauseFlag(cPause_Both);
    }

    ~MethodTreeNode() override { detachAll(); }

    template <typename Delegate>
    void bind(const Delegate& delegate, const char* name)
    {
        lock_();
        mDelegateHolder.construct(delegate);
        unlock_();

        if (name)
            setName(name);
    }

    void call();
    void detachAll();
    void pushBackChild(MethodTreeNode* node);
    void pushFrontChild(MethodTreeNode* node);

    void setPauseFlag(PauseFlag flag)
    {
        lock_();
        if (mPauseEventDelegate)
            mPauseEventDelegate->invoke(this, flag);
        mPauseFlag = flag;
        unlock_();
    }

private:
    void attachMutexRec_(CriticalSection* m) const;
    void callRec_();

    void lock_();
    void unlock_();

    StorageFor<sead::AnyDelegate> mDelegateHolder;
    mutable CriticalSection* mCriticalSection;
    [[maybe_unused]] u32 mPriority;
    BitFlag32 mPauseFlag;
    PauseEventDelegate* mPauseEventDelegate;
    void* mUserID;
};

}  // namespace sead



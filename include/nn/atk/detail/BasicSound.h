/**
 * @file BasicSound.h
 * @brief A basic sound.
 */

#pragma once

#include "types.h"
#include <nn/atk/SoundPlayer.h>

namespace nn {
    namespace atk
    {
        class SoundActor;

        enum MixMode
        {

        };

        namespace detail
        {
            class PlayerHeap;
            class ExternalSoundPlayer;

            class BasicSound
            {
            public:
                BasicSound();
                virtual ~BasicSound();

                virtual void Initialize();
                virtual void Finalize();
                virtual bool IsPrepared() const = 0;
                virtual bool IsAttachedTempSpecialHandle() = 0;
                virtual void DetachTempSpecialHandle() = 0;
                virtual void OnUpdatePlayerPriority();
                virtual void UpdateMoveValue();
                virtual void OnUpdateParam();

                void SetPriority(s32, s32);
                void GetPriority(s32 *, s32 *) const;
                void ClearIsFinalizedForCannotAllocatedResourceFlag();
                void SetId(u32 newID);
                bool IsAttachedGeneralHandle();
                void DetachGeneralHandle();
                bool IsAttachedTempGeneralHandle();
                void DetachTempGeneralHandle();
                void StartPrepared();
                void Stop(s32);
                void SetPlayerPriority(s32);
                void ForceStop();
                void Pause(bool, s32);
                void Mute(bool, s32);
                void SetAutoStopCounter(s32);
                void FadeIn(s32);
                bool IsPause() const;
                bool IsMute() const;
                void Update();
                void UpdateParam();
                void UpdateMoveValue();
                void CalculateVolume() const;
                f32 CalculatePitch() const;
                f32 CalculateLpfFrequency() const;
                u32 CalculateOutLineFlag() const;
                void CalculateBiquadFilter(s32 *, f32 *) const;
                void AttachPlayerHeap(nn::atk::detail::PlayerHeap *);
                void DetachPlayerHeap(nn::atk::detail::PlayerHeap *);
                void AttachSoundPlayer(nn::atk::SoundPlayer *);
                void DetachSoundPlayer(nn::atk::SoundPlayer *);
                void AttachSoundActor(nn::atk::SoundActor *);
                void DetachSoundActor(nn::atk::SoundActor *);
                void AttachExternalSoundPlayer(nn::atk::detail::ExternalSoundPlayer *);
                void DetachExternalSoundPlayer(nn::atk::detail::ExternalSoundPlayer *);
                u32 GetRemainingFadeFrames() const;
                u32 GetRemainingPauseFadeFrames() const;
                u32 GetRemainingMuteFadeFrames() const;
                void SetInitialVolume(f32 vol);
                f32 GetInitialVolume() const;
                void SetVolume(f32, s32);
                s32 GetVolume() const;
                void SetPitch(f32);
                f32 GetPitch() const;
                void SetLpfFreq(f32);
                f32 GetLpfFreq() const;
                void SetBiquadFilter(s32, f32);
                void GetBiquadFilter(s32 *, f32 *) const;
                void SetOutputLine(u32);
                u32 GetOutputLine() const;
                void ResetOutputLine();
                void SetMixMode(nn::atk::MixMode);
                nn::atk::MixMode GetMixMode();
                void SetPan(f32);
                f32 GetPan() const;
                void SetSurroundPan(f32);
                f32 GetSurroundPan() const;
                void SetMainSend(f32);
                f32 GetMainSend() const;

                u64* _8; // nn::atk::detail::PlayerHeap*
                u64* _10; // nn::atk::SoundHandle*
                u64* _18; // nn::atk::SoundHandle*
                nn::atk::SoundPlayer* mSoundPlayer;
                u64* _28; // nn::atk::SoundActor*
                u64* _30; // nn::atk::detail::ExternalSoundPlayer*
                u64* _38; // nn::atk::SoundArchive*
                u8 _40[0xF0-0x40];
                s32 mPriority;
                u32 _F4;
                u32 _F8;
                s32 mAutoStopCounter;
                u64 _100;
                u32 mID;
                u32 _10C;
                u32 _110;
                u32 _114;
                f32 mInitialVolume;
                f32 mPitch;
                f32 mLpfFreq;
                f32 _124;
                u32 mOutputLine;
                f32 _12C;
                f32 mVolume;
                u32 _134;
                u32 _138;
                nn::atk::MixMode mMixMode;
                f32 mPan;
                f32 mSurroundPan;
                f32 mMainSend;
                u8 _14C[0x158-0x14C];
                f32 mOutputVol;
                u8 _15C[0x190-0x15C];
                f32 mOutputPan;
                f32 mOutputSurroundPan;
                f32 mOutputMainSend;
                f32 mOutputFxSend;

                static u64 g_LastInstanceId;
            };
        };
    };
};

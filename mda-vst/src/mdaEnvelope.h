#pragma once

#include "public.sdk/source/vst2.x/audioeffectx.h"

class mdaEnvelope : public AudioEffectX
{
public:
    mdaEnvelope(audioMasterCallback audioMaster);
    ~mdaEnvelope();

    virtual void process(float** inputs, float** outputs, VstInt32 sampleFrames);
    virtual void processReplacing(float** inputs, float** outputs, VstInt32 sampleFrames);
    virtual void setProgramName(char* name);
    virtual void getProgramName(char* name);
    virtual bool getProgramNameIndexed(VstInt32 category, VstInt32 index, char* name);
    virtual void setParameter(VstInt32 index, float value);
    virtual float getParameter(VstInt32 index);
    virtual void getParameterLabel(VstInt32 index, char* label);
    virtual void getParameterDisplay(VstInt32 index, char* text);
    virtual void getParameterName(VstInt32 index, char* text);
    virtual void suspend();

    virtual bool getEffectName(char* name);
    virtual bool getVendorString(char* text);
    virtual bool getProductString(char* text);
    virtual VstInt32 getVendorVersion() { return 1000; }
    virtual VstPlugCategory getPlugCategory() { return kPlugCategEffect; }

protected:
    float fParam1;
    float fParam2;
    float fParam3;
    float fParam4;
    long  mode;
    float env, att, rel, drel, out;

    char programName[32];
};

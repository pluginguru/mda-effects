#pragma once

#include "public.sdk/source/vst2.x/audioeffectx.h"

#define NPARAMS 12       //number of parameters
#define NPROGS   8       //number of programs
#define NOUTS    2       //number of outputs
#define NVOICES 32       //max polyphony
#define SUSTAIN 128
#define SILENCE 0.0001f  //voice choking
#define WAVELEN 422414   //wave data bytes

class mdaEPianoProgram
{
    friend class mdaEPiano;
private:
    float param[NPARAMS];
    char  name[24];
};


struct VOICE  //voice state
{
    VstInt32  delta;  //sample playback
    VstInt32  frac;
    VstInt32  pos;
    VstInt32  end;
    VstInt32  loop;

    float env;  //envelope
    float dec;

    float f0;   //first-order LPF
    float f1;
    float ff;

    float outl;
    float outr;
    VstInt32  note; //remember what note triggered this
};


struct KGRP  //keygroup
{
    VstInt32  root;  //MIDI root note
    VstInt32  high;  //highest note
    VstInt32  pos;
    VstInt32  end;
    VstInt32  loop;
};

class mdaEPiano : public AudioEffectX
{
public:
    mdaEPiano(audioMasterCallback audioMaster);
    ~mdaEPiano();

    virtual void process(float** inputs, float** outputs, VstInt32 sampleframes);
    virtual void processReplacing(float** inputs, float** outputs, VstInt32 sampleframes);
    virtual VstInt32 processEvents(VstEvents* events);

    virtual void setProgram(VstInt32 program);
    virtual void setProgramName(char* name);
    virtual void getProgramName(char* name);
    virtual void setParameter(VstInt32 index, float value);
    virtual float getParameter(VstInt32 index);
    virtual void getParameterLabel(VstInt32 index, char* label);
    virtual void getParameterDisplay(VstInt32 index, char* text);
    virtual void getParameterName(VstInt32 index, char* text);
    virtual void setBlockSize(VstInt32 blockSize);
    virtual void resume();

    virtual bool getOutputProperties(VstInt32 index, VstPinProperties* properties);
    virtual bool getProgramNameIndexed(VstInt32 category, VstInt32 index, char* text);
    virtual bool copyProgram(VstInt32 destination);
    virtual bool getEffectName(char* name);
    virtual bool getVendorString(char* text);
    virtual bool getProductString(char* text);
    virtual VstInt32 getVendorVersion() { return 1; }
    virtual VstInt32 canDo(char* text);
    virtual VstPlugCategory getPlugCategory() { return kPlugCategSynth; }

    virtual VstInt32 getNumMidiInputChannels() { return 1; }

    VstInt32 guiUpdate;
    void guiGetDisplay(VstInt32 index, char* label);

private:
    void update();  //my parameter update
    void noteOn(VstInt32 note, VstInt32 velocity);
    void fillpatch(VstInt32 p, char* name, float p0, float p1, float p2, float p3, float p4,
        float p5, float p6, float p7, float p8, float p9, float p10, float p11);

    mdaEPianoProgram* programs;
    float Fs, iFs;

#define EVENTBUFFER 120
#define EVENTS_DONE 99999999
    VstInt32 notes[EVENTBUFFER + 8];  //list of delta|note|velocity for current block

    ///global internal variables
    KGRP  kgrp[34];
    VOICE voice[NVOICES];
    VstInt32  activevoices, poly;
    short* waves;
    float width;
    VstInt32  size, sustain;
    float lfo0, lfo1, dlfo, lmod, rmod;
    float treb, tfrq, tl, tr;
    float tune, fine, random, stretch, overdrive;
    float muff, muffvel, sizevel, velsens, volume, modwhl;
};

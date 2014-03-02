/*
  ==============================================================================

    PlayContentComponent.cpp
    Created: 14 Feb 2014 2:41:27am
    Author:  Govinda Ram Pingali

  ==============================================================================
*/

#include "PlayContentComponent.h"



PlayContentComponent::PlayContentComponent ()
{
    liveAudioScroller = new LiveScrollingAudioDisplay;
    
//    addAndMakeVisible (liveStreamToggleButton = new TextButton ("liveStreamToggleButton"));
//    liveStreamToggleButton->setButtonText (TRANS("Audio Off"));
//    liveStreamToggleButton->setClickingTogglesState(true);
//    liveStreamToggleButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
//    liveStreamToggleButton->setColour (TextButton::buttonColourId, Colour (0xff3b3b3b));
//    liveStreamToggleButton->setColour (TextButton::buttonOnColourId, Colour (0xff797979));
    
    
    addAndMakeVisible (audioStreamToggleButton = new ImageButton ("playButton"));
    audioStreamToggleButton->setClickingTogglesState(true);
    audioStreamToggleButton->setImages (false, true, true,
                                ImageCache::getFromMemory (BinaryData::Play128_png, BinaryData::Play128_pngSize), 1.0f, Colour (0x00000000),
                                Image::null, 0.7f, Colour (0x00000000),
                                ImageCache::getFromMemory (BinaryData::Stop128_png, BinaryData::Stop128_pngSize), 1.0f, Colour (0x00000000));
    
    
    addAndMakeVisible(liveAudioScroller);
    
    setSize (BeatSurfaceBase::iDocumentInitWidth, BeatSurfaceBase::iDocumentInitHeight);

}

PlayContentComponent::~PlayContentComponent()
{
    audioStreamToggleButton  = nullptr;
    liveAudioScroller       = nullptr;
}



void PlayContentComponent::paint (Graphics& g)
{
    g.fillAll (Colour (0xff2b2b2b));
}

void PlayContentComponent::resized()
{
    //liveStreamToggleButton->setBounds ((getWidth() / 2) - ((120) / 2), (getHeight() / 2) - ((40) / 2), 120, 40);
    liveAudioScroller->setBounds(0, 0, proportionOfWidth (0.5000f), proportionOfHeight (0.2000f));
    audioStreamToggleButton->setBounds(5, getHeight()/2 , 64, 64);
}



bool PlayContentComponent::keyPressed (const KeyPress& key)
{
    return false;  // Return true if your handler uses this key event, or false to allow it to be passed-on.
}


bool PlayContentComponent::keyStateChanged (const bool isKeyDown)
{
    return false;  // Return true if your handler uses this key event, or false to allow it to be passed-on.
}
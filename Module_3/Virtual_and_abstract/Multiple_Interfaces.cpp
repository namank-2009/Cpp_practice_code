#include<iostream>
using namespace std;

// class Playable with virtual play and pause function
class Playable{
    public:
    virtual void play() = 0;
    virtual void pause() = 0;
};

// class Recordable with virtual stop and record function
class Recordable{
    public:
    virtual void stop() = 0;
    virtual void record() = 0;
};

// Created the mediaplayer with playable and recordable inherited
class MediaPlayer : public Playable, public Recordable{
    public: 
    void play() override{
        cout<<"Play the music"<<endl;
    }

    void pause() override{
        cout<<"Pause the music"<<endl;
    }

    void record() override{
        cout<<"Record the music"<<endl;
    }

    void stop() override{
        cout<<"Stop the music"<<endl;
    }
};

int main(){
    // Created the object for mediaplayer
    MediaPlayer mp;
   
    // Created the object for playable and stored the address of mediaplayer
    Playable* p = &mp; 
    p->play(); 
    p->pause();

    // Created the object for Recordable and stored the address of mediaplayer
    Recordable* r = &mp; 
    r->record(); 
    r->stop();

}
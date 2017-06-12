//
// Created by zosiek on 08.05.17.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <string>
#include <sstream>
#include <stdexcept>
#include <regex>

using namespace std;

namespace moviesubs{

    class MovieSubtitles {
    public:
        MovieSubtitles(){}
        virtual ~MovieSubtitles(){}
        virtual void ShiftAllSubtitlesBy(int delay, int fps, stringstream *in, stringstream *out);
    };

    class MicroDvdSubtitles : public MovieSubtitles{
    public:
        MicroDvdSubtitles(){}
        ~MicroDvdSubtitles();

        virtual void ShiftAllSubtitlesBy(int delay, int fps, stringstream *in, stringstream *out);
    };

    class SubRipSubtitles : public MovieSubtitles{
    public:
        SubRipSubtitles(){}
        ~SubRipSubtitles() {}
    };

    class PotatoException : public invalid_argument{
    public:
        PotatoException(const string &str ) : invalid_argument::invalid_argument(str){};
    };

    class NegativeFrameAfterShift : public PotatoException {
    public:
        NegativeFrameAfterShift();
    };

    class SubtitleEndBeforeStart : public PotatoException{
    public:
        SubtitleEndBeforeStart(int line_number,string line);
        int LineAt() const;

    private:
        int line_number;
    };

    class InvalidSubtitleLineFormat : public PotatoException {
    public:
        InvalidSubtitleLineFormat();
    };

    class MissingTimeSpecification : public PotatoException {
    public:
        MissingTimeSpecification();
    };

    class OutOfOrderFrames : public PotatoException {
    public:
        OutOfOrderFrames();
    };
}

#endif //JIMP_EXERCISES_MOVIESUBTITLES_H

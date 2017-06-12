//
// Created by zosiek on 08.05.17.
//
#include "MovieSubtitles.h"

namespace moviesubs {

    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay, int fps, stringstream *in, stringstream *out) {

        string tmp, subs;
        subs = (*in).str();

        if (fps <= 0) throw PotatoException("Invalid argument");

        if (!regex_search (subs, regex("(\\{)[0-9]{1,}(\\}\\{)[0-9]{1,}(\\})(.*)(\n\\{)[0-9]{1,}(\\}\\{)[0-9]{1,}(\\})(.*)\n"))){
           throw InvalidSubtitleLineFormat();
        }
        int line = 0;
        string start, end, text;
        for(int i = 0; i < subs.length(); i++){
            if(subs[i] == '\n') line++;
            else if(subs[i] == '{' && isdigit(subs[i+1])){
                start = "";
                end = "";
                text = "";
                i++;
                while(subs[i] != '}') {
                    start += subs[i];
                    i++;
                }
                i += 2;
                while(subs[i] != '}'){
                    end += subs[i];
                    i++;
                }
                text = text + '{' + start + '}' + '{' + end + '}';
            }
            else text += subs[i];
        }

        if(end < start) throw SubtitleEndBeforeStart(line, text);

        for (string::iterator i = subs.begin(); i < subs.end(); i++) {
            if (*i == '{' && isdigit(*(i + 1))) {
                tmp = "";
                *(i++);
                while (*i != '}') {
                    tmp += *i;
                    *(i++);
                }

                if((atoi(tmp.c_str()) + (delay * fps) / 1000)<0) throw NegativeFrameAfterShift();

                *out << '{' + to_string(atoi(tmp.c_str()) + (delay * fps) / 1000) + '}';
            } else *out << *i;
        }
        if (subs[subs.length() - 1] != '\n') *out << '\n';
    }

    MicroDvdSubtitles::~MicroDvdSubtitles() {}
    
    void MovieSubtitles::ShiftAllSubtitlesBy(int delay, int fps, stringstream *in, stringstream *out) {
    }
    
    NegativeFrameAfterShift::NegativeFrameAfterShift() : PotatoException("NegativeFrameAfterShift") {}
    InvalidSubtitleLineFormat::InvalidSubtitleLineFormat() : PotatoException("InvalidSubtitleLineFormat") {}
    MissingTimeSpecification::MissingTimeSpecification() : PotatoException("MissingTimeSpecification") {}
    OutOfOrderFrames::OutOfOrderFrames() : PotatoException("OutOfOrderFrames") {}
    
    SubtitleEndBeforeStart::SubtitleEndBeforeStart(int line_num, string line) : PotatoException ("At line " + std::to_string(line_num) + ": " + line) {
        this->line_number=line_num;
    }
    int SubtitleEndBeforeStart::LineAt() const {
        return this->line_number;
    }
}
#ifndef _YTDLClass_hh_
#define _YTDLClass_hh_

#include <string>
#include <tuple>
#include <list>

// i am a lazy typist, temporarily shortens "std::string".
#define str std::string

struct YoutubeVideo {
	/* A unique ID that identifies this video in
	   the YoutubeInterface. */
	int internalID;

	/* Used for making sure this Video belongs to whatever
	   interface it is passed to, because the ID is internal
	   to the interface itself. */
	YoutubeInterface whosYourDaddy;
};
typedef struct YoutubeVideo YoutubeVideo;

struct YoutubeFormat {
	int formatID;

	bool hasVideo;
	bool hasAudio;

	// Both ints should be -1 in formats without video.
	std::tuple<int, int> videoResolution;

};
typedef struct YoutubeFormat YoutubeFormat;

class YoutubeInterface {
public:
	/* Download a video to disk. */
	void downloadVideo(YoutubeVideo, str fileName, YoutubeFormat);

	/* Get thumbnail URL for a video. */
	str getThumbnail(YoutubeVideo);

	/* Returns a YoutubeFormat array containing
	   availible formats for this video. */
	std::list<YoutubeFormat> getFormats(YoutubeVideo);

	/* returns an identifier for this video
	   so interfaces don't have to get the video information
	   many times, likely slowing down the application
	   by a LOT. */
	YoutubeVideo getVidInfo(str URI);
};

// we do NOT want to override any other instances of str.
#undef str

#endif
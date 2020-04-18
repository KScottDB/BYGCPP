#pragma once

// Custom C++ API for youtube-dl, written by KScott.
// Makes use of the Python API for youtube-dl.

// "My first class, be gentle! ^_^;"

#include <string>
#include <tuple>
#include <list>
#include <zmq.hpp>
#include <boost/process.hpp>

// i am a lazy typist, temporarily shortens "std::string".
#define str std::string

namespace YoutubeDL {
	// Used for 2-dimensional sizes, etc.
	typedef std::tuple<int, int> Vector2;

	// Make types for the structs
	typedef struct YoutubeFormat YoutubeFormat;
	typedef struct YoutubeVideo YoutubeVideo;

	class YoutubeInterface {
	private:
		/* Are we connected to the Python API? */
		bool connectedToPython = false;

		/* ØMQ Variables */
		zmq::context_t zmqContext;
		zmq::socket_t  zmqSocket;

		/* Python instance */
		boost::process::child pyInstance;

		/* Starts Python API server and connects to it. */
		void connectPy();

		/* Initializes ØMQ variables. */
		void zmqInit();

		/* Debugging output */
		void dbgOutput(std::string output);
	public:
		// TEMPORARY DEBUG FUNCTION.
		void tmpDbg() {
			zmqInit();
			connectPy();
		};

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

	struct YoutubeVideo {

		/* A unique ID that identifies this video in
		the YoutubeInterface. */
		int internalID;

		/* Used for making sure this Video belongs to whatever
		interface it is passed to, because the ID is internal
		to the interface itself. */
		YoutubeInterface whosYourDaddy;

	};

	struct YoutubeFormat {

		int formatID;

		bool hasVideo;
		bool hasAudio;

		// Resolution should be {-1, -1} if (!hasVideo).
		Vector2 videoResolution = {-1, -1};

	};
}

// we do NOT want to override any other instances of str.
#undef str
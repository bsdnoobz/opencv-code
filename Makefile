all:display-histogram eye-tracking pupil-detect quad-segmentation shape-detect straighten-img watershed

display-histogram: display-histogram.cpp
	clang++ display-histogram.cpp -o display-histogram `pkg-config --cflags --libs opencv`
eye-tracking: eye-tracking.cpp
	clang++ eye-tracking.cpp -o eye-tracking `pkg-config --cflags --libs opencv`
pupil-detect: pupil-detect.cpp
	clang++ pupil-detect.cpp -o pupil-detect `pkg-config --cflags --libs opencv`
quad-segmentation: quad-segmentation.cpp
	clang++ quad-segmentation.cpp -o quad-segmentation `pkg-config --cflags --libs opencv`
shape-detect: shape-detect.cpp
	clang++ shape-detect.cpp -o shape-detect `pkg-config --cflags --libs opencv`
straighten-img: straighten-img.cpp
	clang++ straighten-img.cpp -o straighten-img `pkg-config --cflags --libs opencv`
watershed: watershed.cpp
	clang++ watershed.cpp -o watershed `pkg-config --cflags --libs opencv`

clean:
	rm display-histogram eye-tracking pupil-detect quad-segmentation shape-detect straighten-img watershed

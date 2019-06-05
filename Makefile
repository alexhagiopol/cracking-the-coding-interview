configure:
	git submodule update --init && cd cpp_solutions/third_party/eigen && rm -rf build && mkdir build && cd build && cmake -DCMAKE_BUILD_TYPE=Debug .. && sudo make install && cd ../../../.. && rm -rf build && mkdir build && cd build && cmake ..

configure-mac:
	git submodule update --init && ruby -e "$(curl -fsSkL raw.github.com/mxcl/homebrew/go)" && brew install python && easy_install pip && pip install numpy && cd cpp_solutions/third_party/eigen && rm -rf build && mkdir build && cd build && cmake -DCMAKE_BUILD_TYPE=Debug .. && sudo make install && cd ../../../.. && rm -rf build && mkdir build && cd build && cmake ..

configure-ubuntu:
	git submodule update --init && sudo apt-get install -y build-essential cmake python3 python3-numpy && cd cpp_solutions/third_party/eigen && rm -rf build && mkdir build && cd build && cmake -DCMAKE_BUILD_TYPE=Debug .. && sudo make install && cd ../../../.. && rm -rf build && mkdir build && cd build && cmake ..

clean:
	rm -rf build && mkdir build && cd build && cmake ..

test:
	@echo ---------------------
	@echo TESTING C++ SOLUTIONS
	@echo ---------------------
	cd build && make -j6 && ./tests
	@echo ------------------------
	@echo TESTING PYTHON SOLUTIONS
	@echo ------------------------
	python3 tests.py

test_coverage:
	@echo ---------------------
	@echo TESTING C++ SOLUTIONS
	@echo ---------------------
	cd build && make -j6 && ./tests
	@echo ------------------------
	@echo TESTING PYTHON SOLUTIONS
	@echo ------------------------
	coverage run --source=python_solutions tests.py
	coverage report -m

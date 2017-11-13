configure:
	git submodule update --init && cd cpp_solutions/third_party/eigen && rm -rf build && mkdir build && cd build && cmake -DCMAKE_BUILD_TYPE=Debug .. && sudo make install && cd ../../../.. && rm -rf build && mkdir build && cd build && cmake ..

configure-ubuntu:
	git submodule update --init && sudo apt-get install -y build-essential cmake python3 python3-numpy && cd cpp_solutions/third_party/eigen && rm -rf build && mkdir build && cd build && cmake -DCMAKE_BUILD_TYPE=Debug .. && sudo make install && cd ../../../.. && rm -rf build && mkdir build && cd build && cmake ..

clean:
	rm -rf build && mkdir build && cd build && cmake ..

test:
	@echo TESTING C++ SOLUTIONS
	cd build && make -j4 && ./tests
	@echo TESTING PYTHON SOLUTIONS
	python3 tests.py

test_coverage:
	@echo TESTING C++ SOLUTIONS
	cd build && make -j4 && ./tests
	@echo TESTING PYTHON SOLUTIONS
	coverage run --source=python_solutions tests.py
	coverage report -m

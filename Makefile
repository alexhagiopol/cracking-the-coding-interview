configure:
	git submodule update --init && rm -rf build && mkdir build && cd build && cmake ..

clean:
	rm -rf build && mkdir build && cd build && cmake ..

test:
	@echo TESTING C++ SOLUTIONS
	cd build && make -j4 && ./tests
	@echo TESTING PYTHON SOLUTIONS
	python tests.py

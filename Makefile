configure:
	git submodule update --init && cd cpp_solutions/third_party/eigen && rm -rf build && mkdir build && cd build && cmake .. && sudo make install && cd ../../../.. && rm -rf build && mkdir build && cd build && cmake ..

clean:
	rm -rf build && mkdir build && cd build && cmake ..

test:
	@echo TESTING C++ SOLUTIONS
	cd build && make -j4 && ./tests
	@echo TESTING PYTHON SOLUTIONS
	python tests.py

test_coverage:
	@echo TESTING C++ SOLUTIONS
	cd build && make -j4 && ./tests
	@echo TESTING PYTHON SOLUTIONS
	coverage run --source=python_solutions tests.py
	coverage report -m

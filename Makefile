
default:
	${MAKE} -C src

install:
	${MAKE} -C src install
	${MAKE} -C scripts install

clean:
	${MAKE} -C src clean

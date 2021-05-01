all:
	@echo ==Compiling and Linking==
	@gcc src/*.c -o bin/Hethor.exe -Iinclude
	@echo ==DONE COMPLILING TO /bin/hethor.exe==
run:
	@echo ==Running==
	@CMD /c start bin/Hethor.exe
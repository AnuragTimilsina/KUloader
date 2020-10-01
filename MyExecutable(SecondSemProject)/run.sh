# first it looks for package libqt5widgets5 and all its output is sent to /dev/null which is temporary directory.
# apt-cache returns 0 if our libqt5widget is found
# 2>&1 2 means stderror and 1 means standard output. 
# ./ww 2> /home/ash/test.txt means send errors to test.txt file
# ./ww 1> /home/ash/text.txt means send standard output only (not errors) to test.txt
# 2>&1 means take both of them 

# [ is a command which ] evaluates expressions 
# if 0 is sent by previous command. just run it else download it

apt-cache show libqt5widgets5 > /dev/null 2>&1; [ $? -eq 0 ] && echo " dependecies found"; ./KULoader || sudo apt install libqt5widgets5

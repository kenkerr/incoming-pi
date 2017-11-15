IDIR=../include
ODIR=obj

CC=g++
CFLAGS=-I$(IDIR) -std=c++11


DEPS=$(IDIR)/application.h $(IDIR)/logger.h
OBJS=$(ODIR)/io.o $(ODIR)/application.o $(ODIR)/logger.o 

default:  io 

# Create the executable 
#
io: $(OBJS)
	$(CC) $(CFLAGS) -o io $(OBJS) 

testLogger: $(ODIR)/testLogger.o $(ODIR)/logger.o
	$(CC) $(CFLAGS) -o testLogger $(ODIR)/testLogger.o $(ODIR)/logger.o

# Create the necessary object files
#
$(ODIR)/io.o:  io.cpp $(DEPS)
	$(CC) $(CFLAGS) -I/$(IDIR) -c io.cpp -o $(ODIR)/io.o

$(ODIR)/application.o:  application.cpp $(DEPS)
	$(CC) $(CFLAGS) -I/$(IDIR) -c application.cpp -o $(ODIR)/application.o

$(ODIR)/logger.o:  logger.cpp $(DEPS)
	$(CC) $(CFLAGS) -I/$(IDIR) -c logger.cpp -o $(ODIR)/logger.o

$(ODIR)/testLogger.o:  testLogger.cpp $(DEPS)
	$(CC) $(CFLAGS) -I/$(IDIR) -c testLogger.cpp -o $(ODIR)/testLogger.o

clean:
	rm -f $(ODIR)/*.o *~


#######################################
#   more ambitious version 
#
#$(ODIR)/%.o: %.cpp $(DEPS)
#	$(CC) -c -o $@ $< $(CFLAGS)

#LV_Lights: $(OBJ) 
#	$(CC) -o $@ $^ $(CFLAGS)
#######################################



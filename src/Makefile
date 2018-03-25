IDIR=../include
ODIR=obj
BDIR=../bin
LDIR=../lib

CC=g++
CFLAGS=-I$(IDIR) -std=c++11

DEPS=$(IDIR)/application.h $(IDIR)/logger.h 
SPTOBJS=$(ODIR)/application.o $(ODIR)/logger.o 
LIBS=$(LDIR)

default:  io configure ioComMgr cmdServer

# Create the executable 
#
io: $(SPTOBJS) $(ODIR)/io.o
	$(CC) $(CFLAGS) -o $(BDIR)/io $(ODIR)/io.o $(SPTOBJS) 

configure: $(SPTOBJS) $(ODIR)/configure.o
	$(CC) $(CFLAGS) -o $(BDIR)/configure $(ODIR)/configure.o $(SPTOBJS) -L$(LDIR) -ltinyxml2

testLogger: $(ODIR)/testLogger.o $(ODIR)/logger.o
	$(CC) $(CFLAGS) -o $(BDIR)/testLogger $(ODIR)/testLogger.o $(ODIR)/logger.o

cmdServer: $(SPTOBJS) $(ODIR)/cmdServer.o $(ODIR)/ioComMgr.o $(ODIR)/logger.o
	$(CC) $(CFLAGS) -o $(BDIR)/cmdServer $(ODIR)/cmdServer.o $(ODIR)/ioComMgr.o $(SPTOBJS) -L$(LDIR) 

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

$(ODIR)/configure.o:  configure.cpp $(DEPS)
	$(CC) $(CFLAGS) -I/$(IDIR) -c configure.cpp -o $(ODIR)/configure.o

$(ODIR)/ioComMgr.o:  ioComMgr.cpp $(DEPS)
	$(CC) $(CFLAGS) -I/$(IDIR) -c ioComMgr.cpp -o $(ODIR)/ioComMgr.o

$(ODIR)/cmdServer.o:  cmdServer.cpp $(DEPS)
	$(CC) $(CFLAGS) -I/$(IDIR) -c cmdServer.cpp -o $(ODIR)/cmdServer.o

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



IDIR=../include
ODIR=obj

CC=g++
CFLAGS=-I$(IDIR)


DEPS=$(IDIR)/application.h 
OBJS=$(ODIR)/io.o $(ODIR)/application.o

default:  io

# Create the executable 
#
io: $(OBJS)
	$(CC) $(CFLAGS) -o io $(OBJS) 

# Create the necessary object files
#
$(ODIR)/io.o:  io.cpp $(DEPS)
	$(CC) $(CFLAGS) -I/$(IDIR) -c io.cpp -o $(ODIR)/io.o

$(ODIR)/application.o:  application.cpp $(DEPS)
	$(CC) $(CFLAGS) -I/$(IDIR) -c application.cpp -o $(ODIR)/application.o

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



CC=g++
CFLAGS=-c -g 
LDFLAGS=
BINDIR=bin
SRCDIR=src
OBJDIR=obj
SOURCES=$(SRCDIR)/main.cpp $(SRCDIR)/arvbin.cpp $(SRCDIR)/pilha.cpp $(SRCDIR)/tipocel.cpp $(SRCDIR)/tipono.cpp
OBJECTS=$(OBJDIR)/main.o $(OBJDIR)/arvbin.o $(OBJDIR)/pilha.o $(OBJDIR)/tipocel.o $(OBJDIR)/tipono.o
EXECUTABLE=$(BINDIR)/programa
.IGNORE: run

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJDIR)/*
	rm -f $(BINDIR)/programa
run: 
	./$(EXECUTABLE) $(BINDIR)/entdouble.s1.n5.i.in
	./$(EXECUTABLE) $(BINDIR)/entdouble.s2.n5.p.in
	./$(EXECUTABLE) $(BINDIR)/entdouble.s3.n5.i.in
	./$(EXECUTABLE) $(BINDIR)/entdouble.s4.n5.p.in
	./$(EXECUTABLE) $(BINDIR)/entdouble.s5.n5.i.in
	./$(EXECUTABLE) $(BINDIR)/entdouble.s6.n5.p.in
	./$(EXECUTABLE) $(BINDIR)/entdouble.s7.n5.i.in
	./$(EXECUTABLE) $(BINDIR)/entdouble.s8.n5.p.in
	./$(EXECUTABLE) $(BINDIR)/entdouble.s11.n10.i.in
	./$(EXECUTABLE) $(BINDIR)/entdouble.s12.n10.p.in
	./$(EXECUTABLE) $(BINDIR)/entdouble.s13.n10.i.in
	./$(EXECUTABLE) $(BINDIR)/entdouble.s14.n10.p.in
	./$(EXECUTABLE) $(BINDIR)/entdouble.s15.n10.i.in
	./$(EXECUTABLE) $(BINDIR)/entdouble.s16.n10.p.in
	./$(EXECUTABLE) $(BINDIR)/entdouble.s17.n10.i.in
	./$(EXECUTABLE) $(BINDIR)/entdouble.s18.n10.p.in
	./$(EXECUTABLE) $(BINDIR)/entdouble.s21.n25.i.in
	./$(EXECUTABLE) $(BINDIR)/entdouble.s22.n25.p.in
	./$(EXECUTABLE) $(BINDIR)/entdouble.s23.n25.i.in
	./$(EXECUTABLE) $(BINDIR)/entdouble.s24.n25.p.in
	./$(EXECUTABLE) $(BINDIR)/entdouble.s25.n25.i.in
	./$(EXECUTABLE) $(BINDIR)/entdouble.s26.n25.p.in
	./$(EXECUTABLE) $(BINDIR)/entdouble.s27.n25.i.in
	./$(EXECUTABLE) $(BINDIR)/entdouble.s28.n25.p.in
	./$(EXECUTABLE) $(BINDIR)/entdouble.s31.n50.i.in
	./$(EXECUTABLE) $(BINDIR)/entdouble.s32.n50.p.in
	./$(EXECUTABLE) $(BINDIR)/entdouble.s33.n50.i.in
	./$(EXECUTABLE) $(BINDIR)/entdouble.s34.n50.p.in
	./$(EXECUTABLE) $(BINDIR)/entdouble.s35.n50.i.in
	./$(EXECUTABLE) $(BINDIR)/entdouble.s36.n50.p.in
	./$(EXECUTABLE) $(BINDIR)/entdouble.s37.n50.i.in
	./$(EXECUTABLE) $(BINDIR)/entdouble.s38.n50.p.in
	./$(EXECUTABLE) $(BINDIR)/erro.1000.in
	./$(EXECUTABLE) $(BINDIR)/erro.caracintrusodec.p.in
	./$(EXECUTABLE) $(BINDIR)/erro.caracinv.i.in
	./$(EXECUTABLE) $(BINDIR)/erro.caracinv.p.in
	./$(EXECUTABLE) $(BINDIR)/erro.caracterenodecimal.i.in
	./$(EXECUTABLE) $(BINDIR)/erro.difopernum.p.in
	./$(EXECUTABLE) $(BINDIR)/erro.divzeroinf.i.in
	./$(EXECUTABLE) $(BINDIR)/erro.divzeropos.i.in
	./$(EXECUTABLE) $(BINDIR)/erro.doisnumseq.i.in
	./$(EXECUTABLE) $(BINDIR)/erro.doisoperseq.i.in
	./$(EXECUTABLE) $(BINDIR)/erro.doispontodecimal.p.in
	./$(EXECUTABLE) $(BINDIR)/erro.doispontos.i.in
	./$(EXECUTABLE) $(BINDIR)/erro.fechaparantesnum.i.in
	./$(EXECUTABLE) $(BINDIR)/erro.infnaoexiste.i.in
	./$(EXECUTABLE) $(BINDIR)/erro.insuf.p.in
	./$(EXECUTABLE) $(BINDIR)/erro.naorespeitaenunciado.i.in
	./$(EXECUTABLE) $(BINDIR)/erro.naosuficiente.i.in
	./$(EXECUTABLE) $(BINDIR)/erro.operdpspar_a.i.in
	./$(EXECUTABLE) $(BINDIR)/erro.pardpsoper.i.in
	./$(EXECUTABLE) $(BINDIR)/erro.posnaoexiste.p.in
	./$(EXECUTABLE) $(BINDIR)/erro.primelemoper.i.in
	./$(EXECUTABLE) $(BINDIR)/erro.primnaonum.p.in
	./$(EXECUTABLE) $(BINDIR)/erro.resolvenaoexiste.i.in
	./$(EXECUTABLE) $(BINDIR)/erro.ultimnaooper.p.in



	
	
	
	
	
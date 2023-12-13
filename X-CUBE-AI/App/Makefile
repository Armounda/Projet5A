# X-CUBE-AI/App Makefile
AI_INCDIR = -IInc
AI_LIBDIR = -LLib
AI_LIBS = -lNetworkRuntime810_CM4_GCC
AI_SRCS = $(wildcard X-CUBE-AI/App/*.c)
AI_OBJS = $(AI_SRCS:.c=.o)

# Extract header files from source files
AI_HEADERS = $(wildcard X-CUBE-AI/App/*.h)

$(info "Sub-Makefile for X-CUBE-AI/App is being executed.")
$(info "AI_SRCS: $(AI_SRCS)")
$(info "AI_HEADERS: $(AI_HEADERS)")

X-CUBE-AI/App: $(AI_OBJS)
	$(CC) $(LDFLAGS) $(AI_LIBDIR) $(AI_LIBS) $^ -o $@

# Rule to compile .c files to .o files
$(AI_OBJS): %.o: %.c $(AI_HEADERS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(AI_INCDIR) -c $< -o $@

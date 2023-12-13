# Middlewares/ST/AI/Makefile
AI_INCDIR = -IInc
AI_LIBDIR = -LLib
AI_LIBS = -lNetworkRuntime810_CM4_GCC
AI_SRCS = $(wildcard Middlewares/ST/AI/Inc/*.h)
AI_OBJS = $(AI_SRCS:.h=.o)

$(info "Sub-Makefile for Middlewares/ST/AI is being executed.")
$(info "AI_SRCS: $(AI_SRCS)")

Middlewares/ST/AI: $(AI_OBJS)
	$(info "Something is being added.")
	$(CC) $(LDFLAGS) $(AI_LIBDIR) $(AI_LIBS) $^ -o $@

$(AI_OBJS): %.o: %.c
	$(info "Something is being added.")
	$(CC) $(CFLAGS) $(CPPFLAGS) $(AI_INCDIR) -c $< -o $@

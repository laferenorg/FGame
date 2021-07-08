/* MIT License
 *
 * Copyright (c) 2021 laferenorg
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN C
 */

/* Include pre compile header */
#include "pch.h"

/* Include header C++ */
#include <iostream>
#include <vector>

/* Include header library SDL2 */
#include <SDL2/SDL.h>
#include <SDL2/SDL_net.h>

/* Include header from include directory in this project */
#include "Run/FGNet.hpp"
#include "FGStruct.hpp"

/* Handle function create server */
void FGNet::server(FG_Net& net, int port,
	FGData_System& system, std::string& message_error, bool& errorEvent) {
	/* Check if have error before */
	if(errorEvent) {
		/* if have error */
		/* Write message error */
		message_error = "Can't run Make Server because, you have error ";
		message_error += "before you running this function ";
		message_error += "| in function FGNet::server";
	} else {
		/* If no have error */
		/* Resolve host and check have error */
		if(SDLNet_ResolveHost(&net.ip, NULL, port) == 0) {
			net.socket = SDLNet_TCP_Open(&net.ip);
		} else {
			/* If have error or somthing */
			/* Set error event into true */
			errorEvent = true;

			/* Write message error */
			message_error = ((std::string)SDLNet_GetError());
		}
	}
}

/* Handle function create client */
void FGNet::client(FG_Net& net, std::string host, int port,
	FGData_System& system, std::string& message_error, bool& errorEvent) {
	/* Check if have error before */
	if(errorEvent) {
		/* if have error */
		/* Write message error */
		message_error = "Can't run Make Client because, you have error ";
		message_error += "before you running this function ";
		message_error += "| in function FGNet::client";
	} else {
		/* If no have error */
		/* Resolve host and check have error */
		if(SDLNet_ResolveHost(&net.ip, host.c_str(), port) == 0) {
			net.socket = SDLNet_TCP_Open(&net.ip);
		} else {
			/* If have error or somthing */
			/* Set error event into true */
			errorEvent = true;

			/* Write message error */
			message_error = ((std::string)SDLNet_GetError());
		}
	}
}

/* Handle function accept someone */
void FGNet::accept(FG_Net& net_server, FG_Net& net_client,
	FGData_System& system, std::string& message_error, bool& errorEvent) {
	/* Check if have error before */
	if(errorEvent) {
		/* if have error */
		/* Write message error */
		message_error = "Can't run accept because, you have error ";
		message_error += "before you running this function ";
		message_error += "| in function FGNet::accept";
	} else {
		/* If no have error */
		/* Just do accept server into client */
		net_client.socket = SDLNet_TCP_Accept(net_server.socket);
	}
}

/* Handle function send data */
void FGNet::send(FG_Net& net, const void* data_send, const unsigned int data_len,
	FGData_System& system, std::string& message_error, bool& errorEvent) {
	/* Check if have error before */
	if(errorEvent) {
		/* if have error */
		/* Write message error */
		message_error = "Can't run send because, you have error ";
		message_error += "before you running this function ";
		message_error += "| in function FGNet::send";
	} else {
		/* If no have error */
		/* Just do send data to someone */
		SDLNet_TCP_Send(net.socket, data_send, data_len);
	}
}

/* Handle function send data */
void FGNet::recv(FG_Net& net, const void* data_recv, const unsigned int data_len,
	FGData_System& system, std::string& message_error, bool& errorEvent) {
	/* Check if have error before */
	if(errorEvent) {
		/* if have error */
		/* Write message error */
		message_error = "Can't run recive because, you have error ";
		message_error += "before you running this function ";
		message_error += "| in function FGNet::recv";
	} else {
		/* If no have error */
		/* Just do recive data from someone */
		SDLNet_TCP_Send(net.socket, data_recv, data_len);
	}
}

void FGNet::close(FG_Net& net, const void* data_send, const unsigned int data_len,
	FGData_System& system, std::string& message_error, bool& errorEvent) {
	/* Check if have error before */
	if(errorEvent) {
		/* if have error */
		/* Write message error */
		message_error = "Can't run close because, you have error ";
		message_error += "before you running this function ";
		message_error += "| in function FGNet::close";
	} else {
		/* If no have error */
		/* Just do close connection */
		SDLNet_TCP_Close(net.socket);
	}
}
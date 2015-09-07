/**
 * @brief Initializes USART1 as a print terminal to the PC. This function
 * must check the incoming baudrate against the valid baudrates
 * from the data-sheet. If the baudrate is invalid, then the
 * DEFAULT_BAUD constant must be used instead.
 *
 * @param baudrate The desired baudrate to set for USART1.
 *
 * @todo Create the function that will initialize USART1 for debugging use.
 */
void debugUSARTInit(unsigned long baudrate){
	/*
	Set baud rate
	 */
	UBRRnH = (unsigned char)(baudrate>>8);
	UBRRnL = (unsigned char)baudrate;
	/*
	Enable receiver and transmitter
	 */
	UCSRnB = (1<<RXENn)|(1<<TXENn);
	/*
	Set frame format: 8data, 2stop bit
	 */
	UCSRnC = (1<<USBSn)|(3<<UCSZn0);
}

/**
 * @brief Sends one byte to the USART1 Tx pin (Transmits one byte).
 *
 * @param byteToSend The byte that is to be transmitted through USART1.
 *
 * @todo Make the function that will put a character on the USART1 TX line.
 */
void putCharDebug(char byteToSend){
	/*
	Wait for empty transmit buffer
	 */
	while
	 ( !( UCSRnA & (1<<UDREn)) )
	;
	/*
	Put data into buffer, sends the data
	 */
	UDRn = byteToSend;
}

/**
 * @brief Recieves one byte of data from the serial port (i.e. from the PC).
 *
 * @return byteReceived Character that was received on the USART.
 *
 * @todo Make the function that will listen for input on the USART1 RX line.
 */
unsigned char getCharDebug(void){
	/*
	Wait for data to be received
	 */
	while( !(UCSRnA & (1<<RXCn)) );
	/*
	Get and return received data from buffer
	 */
	return UDRn;

}

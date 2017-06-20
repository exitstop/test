#include <event2/event.h>
#include <event2/bufferevent.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void bufev_callback( struct bufferevent *buf_ev, short events, void *ptr )
{
  if( events & BEV_EVENT_CONNECTED )
  {
    printf( "Соединение установлено\n" );
    /* Здесь можно было бы выполнить и более полезные операции,
     * например, чтение или запись данных
     */
  }
  else if( events & BEV_EVENT_ERROR )
  {
    exit(-1);
    /* Перед принудительным завершением программы при необходимости
     * выполняются "спасательные действия" (освобождение памяти,
     * закрытие файлов и т.д.), если это возможно
     */
  }
}

int main( int argc, char* argv[] )
{
  struct event_base *base;
  struct bufferevent *buf_ev;
  struct sockaddr_in sin;

  base = event_base_new();

  memset( &sin, 0, sizeof(sin) );
  sin.sin_addr.s_addr = inet_addr( "127.0.0.1" );
  sin.sin_port = htons( 8080 );

  buf_ev = bufferevent_socket_new( base, -1, BEV_OPT_CLOSE_ON_FREE );
  bufferevent_setcb( buf_ev, NULL, NULL, bufev_callback, NULL );

  if( bufferevent_socket_connect( buf_ev, (struct sockaddr *)&sin, sizeof(sin) ) < 0 )
  {
    /* Попытка установить соединение была неудачной */
    bufferevent_free( buf_ev ); /* сокет закроется автоматически; см. флаг при создании */
    return -1;
  }

  event_base_dispatch( base );
  return 0;
}



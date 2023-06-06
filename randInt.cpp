/*
 * crate list or vectors to use as samples for my projects
*/
#include <iostream>
#include <random>
#include <getopt.h>
#include <cstdlib>
#include <string>


void print( const int &, const int &, const int &, const char & );


int main( int argc, char *argv[ ] ){

    int st = 0, ed = 20, ct= 10;
    char ch = 'c';

    std::string tt;
    int option_index;
	while( ( option_index = getopt( argc, argv, "s:e:c:t:" ) ) != -1 ){
		switch( option_index ){
			case 's':
				st = atoi( optarg );
                break;
			case 'e':
				ed = atoi( optarg );
				break;
			case 'c':
				ct = atoi( optarg );
				break;
            case 't':
                tt.assign( optarg );
                ch = tt[ 0 ];
                break;
		}
	}
	if( st > 1 && ed <= st ){
		ed = st + 10;
	}

    print( st, ed, ct, ch );
    return 0;
}


void print( const int &st, const int &ed, const int &cn, const char &ch ){
    std::default_random_engine gen( ( std::random_device( ) ) ( ) );
    std::uniform_int_distribution<int> dis( st, ed );
    if( ch == 'c' ){
        std::cout << "{ ";
        for( int i = 0; i < cn; i++ ){
            std::cout <<  dis( gen );
            if( i < cn - 1 ){
                std::cout << ", ";
            }
        }
        std::cout << " };" << std::endl;
    } else if( ch == 'p' ){
        std::cout << "[ ";
        for( int i = 0; i < cn; i++ ){
            std::cout << dis( gen );
            if( i < cn - 1 )
                std::cout << ", ";
        }
        std::cout << " ]" << std::endl;
    } else if( ch == 'n' ){
        for( int i = 0; i < cn; i++ ){
            std::cout << dis( gen ) << " ";
        }
        std::cout << std::endl;
    }
}

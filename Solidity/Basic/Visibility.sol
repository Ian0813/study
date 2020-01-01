

        pragma solidity >= 0.4.24 <= 0.6.0;

        contract Visibility {
            int public b = 78;
            int internal c = 90;


            constructor() public
            {
                // external access
                this.a();

                // compiler error, because this is inside call.
                // a();

                // internal access
                b = 21;

                //external access
                this.b;

                // external access
                this.b();

                // compiler error
                this.b();

                // compiler error
                //this.c();

                //internal access
                c = 9;
            }

            function a() external
            {

            }
        }

        contract sample2
        {
            int internal d = 9;
            int private e = 90;
        }

        // smaple3 inherits sample2
        contract sample3 is sample2
        {
            Visibility s;

            constructor() public
            {
                s = new Visibility();

                //external access
                s.a();

                // external access
                var f = s.b;

                // compiler error as accessor cannot used to assign a value
                //s.b = 18;

                //compiler error
                //s.c();

                //internal access
                d = 8;

                //compiler error
                //e = 7;
            }
        }

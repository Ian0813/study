

            pragma solidity >= 0.4.24 <= 0.6.0;

            contract proof {
                struct FileDetails
                {
                    uint timestamp;
                    string owner;
                }

                mapping (string => FileDetails) files;

                event logFileAddedStatus(bool status, uint timestamp, string owner, string fileHash);

                // this is used to store the owner of file at the block timestamp.
                function set(string memory owner, string memory fileHash) public
                {
                        /* There is no proper way  to check if a key already exists or not therefore
                            we are chenking for default value i.e, all bits are 0 */
                        if(files[fileHash].timestamp == 0)
                        {
                            // block.timestamp (uint) : The current block timestamp.
                            files[fileHash] = FileDetails(block.timestamp, owner);

                            /* we are triggering an event so that the fronted of our app knows that the file's existance
                                and ownership details have been stored */
                            emit logFileAddedStatus(true, block.timestamp, owner, fileHash);
                        }
                        else
                        {
                            /* this tells to the fronted that file's existance and ownership
                                details couldn't be stored because the file's details had already benn stored eariler. */
                            emit logFileAddedStatus(false, block.timestamp, owner, fileHash);
                        }
                }

                // this is used to get file information.
                function get(string memory fileHash) public view returns (uint timestamp, string memory owner) {
                    return (files[fileHash].timestamp, files[fileHash].owner);
                }


            }

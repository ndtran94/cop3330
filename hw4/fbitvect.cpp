/e 'f':
*isptr >> index;
if (BATCH)  std::cout << selection << index << '\n'; // echo input
bvptr->Flip(index);
break;
 case 't': case 'T':
*isptr >> index;
if (BATCH)  std::cout << selection << index << '\n'; // echo input
std::cout << "  v[" << index << "] == ";
if (bvptr->Test(index))
  std::cout << "1\n";
 else
   std::cout << "0\n";
break;
 case 'd': case 'D':
if (BATCH)  std::cout << selection << '\n'; // echo input
std::cout << " v.Size(): " << bvptr -> Size() << " ; v.Dump(std::cout):\n";
bvptr->Dump(std::cout);
break;
 case 'o': case 'O':
if (BATCH)  std::cout << selection << '\n'; // echo input
std::cout << "std::cout << v: " << *bvptr << '\n';
break;
 case 'm': case 'M':
if (BATCH)  std::cout << selection << '\n'; // echo input
DisplayMenu(size);
break;
 case 'x': case 'X':
if (BATCH)
  {
    std::cout << selection << '\n'; // echo input
    isptr = &std::cin;
    ifs.close();
    BATCH = 0;
    std::cout << " ** switched to interactive mode\n";
  }
 else
   {
     std::cout << " ** already in interactive mode\n";
   }
break;
 case 'q': case 'Q': 
if (BATCH)  std::cout << selection << '\n'; // echo input
selection = 'Q';
if (BATCH)
  ifs.close();
break;
 default:
if (BATCH)  std::cout << selection << '\n'; // echo input
std::cout << "  command not found\n";
}
}
while (selection != 'Q');
delete bvptr;
std::cout << "Thank you for testing BitVector\n";
return 0;
}

void DisplayMenu(unsigned int size)
{
  std::cout << "     BitVector (" << size << ") v;\n"   
	    << "     operation                                entry\n"
	    << "     ---------                                -----\n"
	    << "     v.Set      ()  ............................  S\n"
	    << "     v.Set      (index)  .......................  s\n"
	    << "     v.Unset    ()  ............................  U\n"
	    << "     v.Unset    (index)  .......................  u\n"
	    << "     v.Flip     ()  ............................  F\n"
	    << "     v.Flip     (index)  .......................  f\n"
	    << "     v.Test     (index)  .......................  t\n"
	    << "     v.Dump     (std::cout)  ...................  d\n"
	    << "     std::cout << v  ...........................  o\n"
	    << "     copy, assign tests  .......................  =\n"
	    << "     display this Menu  ........................  m\n"
	    << "     switch to interactive mode  ...............  x\n"
	    << "     Quit program  .............................  q\n";
}


void CopyTest(fsu::BitVector bv)
{
  std::cout << "CopyTest:\n";
  std::cout << "Copied object   size: " << bv.Size() << '\n'
            << "                Dump:\n";
  bv.Dump(std::cout);
  std::cout << '\n';
}

void AssignTest(fsu::BitVector * ptr)
{
  fsu::BitVector bv(0);
  bv  = *ptr;
  std::cout << "AssignTest:\n"
            << "Original object size: " << ptr->Size() << '\n'
            << "                Dump:\n";
  ptr->Dump(std::cout);
  std::cout << '\n';
  std::cout << "Assignee object size: " << bv.Size() << '\n'
            << "                Dump:\n";
  bv.Dump(std::cout);
  std::cout << '\n';
}

// find duplicates
//

int dups(vector<int128> & list)
{
  int count=0;
  sort(list.begin(),list.end()); // sort the list
  for(int i=1; i<list.size(); i++)
  {
    if(list[i]==list[i-1]) // duplicate found!
    {
      cout << list[i] << endl;
      count++;
    }
  }
  return count;
}

int dups(vector<int128> & list1, vector<int128> & list2)
{
  int count=0;
  // sort both lists
  sort(list1.begin(),list1.end()); // sort the list
  sort(list2.begin(),list2.end()); // sort the list
				   //
  int j=0;
  for(int i=0; i<list1.size(); i++)
  {
    while(list2[j]<list1[i]) j++;
    if(list1[i]==list2[j])
    {
      cout << list1[i] << endl;
      count++;
    }
  }
  return count;
}

int dups(vector<int128> & list1, vector<int128> & list2, ofstream & f)
{
  int count=0;
  // sort both lists
  sort(list1.begin(),list1.end()); // sort the list
  sort(list2.begin(),list2.end()); // sort the list
				   //
  int j=0;
  for(int i=0; i<list1.size(); i++)
  {
    while(j<list2.size() && list2[j]<list1[i]) j++;
    if(list1[i]==list2[j])
    {
      f << list1[i] << endl;
      count++;
    }
  }
  return count;
}

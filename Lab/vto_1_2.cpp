struct Red{
  int items;
};
void calc(Red &studenti,Red &polozeni,Red &nepolozeni){
  Red temp;
  while(!stdenti.empty()){
    if(studenti.peek().poeni > 60)
      polozeni.push(studenti.pop());
    else if (studenti.peek().poeni > 30)
        nepolozeni.push(studenti.pop());
    else
     temp.push(studenti.pop());
  }
  while(!temp.empty())
  nepolozeni.push(temp.pop())

}

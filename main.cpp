


int main()
{
    gout.open(400, 400);
    gout << text("hello ITK, hello flugi!") << refresh;
    event ev;
    while(gin >> ev && ev.keycode != key_escape) {
		
	}
    return 0;
}

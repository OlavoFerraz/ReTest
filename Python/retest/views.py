from django.shortcuts import render, HttpResponse

def login(request):
	return render(request,'retest/login.html')
	#return HttpResponse('Olá')
def report(request):
	return render(request,'retest/report.html')
	#return HttpResponse('Bom dia')
def enviar(request):
	return render(request,'retest/enviar.html')
	#return HttpResponse('olavo')





from django.shortcuts import render
from django.http import HttpResponse

def home(request):
  return render(request,  'home.html', {'name':'Gref Lim'})
# Create your views here.

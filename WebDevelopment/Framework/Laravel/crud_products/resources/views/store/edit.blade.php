@extends('store.layout')
@section('content')
  
<div class="card" style="margin:20px;">
  <div class="card-header">Edit Store</div>
  <div class="card-body">
       
      <form action="{{ url('store/' .$store->id) }}" method="post">
        {!! csrf_field() !!}
        @method("PATCH")
        <input type="hidden" name="id" id="id" value="{{$store->id}}" id="id" />

        <label>Name</label></br>
        <input type="text" name="name" id="name" value="{{$store->name}}" class="form-control"></br>
        
        <label>Mail</label></br>
        <input type="mail" name="mail" id="mail" value="{{$store->mail}}" class="form-control"></br>
        
        <input type="submit" value="Update" class="btn btn-success"></br>
    </form>
    
  </div>
</div>
  
@stop
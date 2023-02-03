@extends('store.layout')
@section('content')
  
<div class="card" style="margin:20px;">
  <div class="card-header">Create New Store</div>
  <div class="card-body">
       
      <form action="{{ url('store') }}" method="post">
        {!! csrf_field() !!}

        <label>Name</label></br>
        <input type="text" name="name" id="name" class="form-control"></br>

        <label>Mail</label></br>
        <input type="mail" name="mail" id="mail" class="form-control"></br>

        <input type="submit" value="Save" class="btn btn-success"></br>
    </form>
    @if($errors->any())
      <div>
        @foreach($errors->all() as $err)
          {{ $err }}
        @endforeach
      </div>
    @endif
  </div>
</div>
  
@stop
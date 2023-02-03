@extends('products.layout')
@section('content')
  
<div class="card" style="margin:20px;">
  <div class="card-header">Edit Product</div>
  <div class="card-body">
       
      <form action="{{ url('products/' .$products->id) }}" method="post">
        {!! csrf_field() !!}
        @method("PATCH")
        <input type="hidden" name="id" id="id" value="{{$products->id}}" id="id" />

        <label>Name</label></br>
        <input type="text" name="name" id="name" value="{{$products->name}}" class="form-control"></br>
        
        <label>value</label></br>
        <input type="text" name="value" id="value" value="{{$products->value}}" class="form-control"></br>
            
        <input hidden type="text" name="store_id" id="store_id" value="{{$products->store_id}}" class="form-control">

        <label>Active</label></br>
        <input type="text" name="is_active" id="is_active" value="{{$products->is_active}}" class="form-control"></br>

        <input type="submit" value="Update" class="btn btn-success"></br>
    </form>
    
  </div>
</div>
  
@stop
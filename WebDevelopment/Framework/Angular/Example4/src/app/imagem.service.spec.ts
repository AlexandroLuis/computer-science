import { TestBed } from '@angular/core/testing';

import { ImagemService } from './imagem.service';

describe('ImagemService', () => {
  let service: ImagemService;

  beforeEach(() => {
    TestBed.configureTestingModule({});
    service = TestBed.inject(ImagemService);
  });

  it('should be created', () => {
    expect(service).toBeTruthy();
  });
});
